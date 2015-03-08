#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
using namespace std;

struct nod
{
  vector<int> vec_path;
  int bike;
  int dis;
};

int bike_send=0x7fffffff,bike_bac=0x7fffffff,c_max;
vector<int> path;
vector<nod> station;

void dfs(int i,vector<int> &vec_path_)
{
  vec_path_.push_back(i);
  if (i==0)
  {
    int temp_send=0,temp_back=0;
    int up_back=0;
    vector<int> temp_path;
    for (int i=vec_path_.size()-1;i>=0;--i)
    {
      int idx=vec_path_[i];
      temp_path.push_back(idx);
      temp_back=up_back+station[idx].bike>c_max?up_back+station[idx].bike-c_max:0;
      temp_send+=(up_back+station[idx].bike>c_max?0:c_max-station[idx].bike-up_back);
      up_back=temp_back;
    }
    if (temp_send<bike_send ||temp_send==bike_send&&temp_back<bike_bac)
    {
      bike_send=temp_send;
      bike_bac=temp_back;
      path=temp_path;
    }
    return ;
  }
  for (int j=0;j<station[i].vec_path.size();++j)
  {
    dfs(station[i].vec_path[j],vec_path_);
    vec_path_.pop_back();
  }
}


int main()
{
  int dist[505][505];
  for(int i=0;i<505;++i)
  {
    for (int j=0;j<505;++j)
    {
      dist[i][j]=-1;
    }
  }
  int n,sp,m;
  scanf("%d %d %d %d",&c_max,&n,&sp,&m);
  c_max/=2;
  n++;
  station.resize(n);
  vector<int> dist_all(n,0x7fffffff);
  vector<bool> vist(n,false);
  for(int i=1;i<n;++i)
  {
    scanf("%d",&station[i].bike);
  }
  for (int i=0;i<m;++i)
  {
    int k,t,d;
    scanf("%d %d %d",&k,&t,&d);
    dist[k][t]=d;
    dist[t][k]=d;
  }
  dist_all[0]=0;
  station[0].dis=0;
  station[0].bike=c_max;
  for (int id=1;id<n;++id)
  {
    vector<int>::iterator min_it=min_element(dist_all.begin(),dist_all.end());
    int deal_idx=min_it-dist_all.begin();
    vist[deal_idx]=true;
    for (int i=0;i<n;++i)
    {
      if (vist[i]==false)
      {
        if (dist[deal_idx][i]>=0)
        {
          if (station[deal_idx].dis+dist[deal_idx][i]<dist_all[i])
          {
            dist_all[i]=station[deal_idx].dis+dist[deal_idx][i];
            station[i].dis=dist_all[i];
            station[i].vec_path.clear();
            station[i].vec_path.push_back(deal_idx);
          }else if (station[deal_idx].dis+dist[deal_idx][i]==dist_all[i])
          {
            station[i].vec_path.push_back(deal_idx);
          }
        }
      }
    }
    dist_all[deal_idx]=0x7fffffff;
  }
  vector<int> vec_path_;
  dfs(sp,vec_path_);
  printf("%d 0",bike_send);
  for (int i=1;i<path.size();++i)
  {
    printf("->%d",path[i]);
  }
  printf(" %d\n",bike_bac);
  system("pause");
  return 0;
}