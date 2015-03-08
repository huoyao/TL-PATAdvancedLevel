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

struct Node
{
  int dist;
  int cost;
  vector<int> vec_path;
};

int dst[505][505];
int cst[505][505];

int main()
{
 // while(1)
  {
    int n,m,s,d;
    Node nod;
    nod.dist=0x7fffffff;
    nod.cost=0x7fffffff;
    //nod.cost
    vector<Node> vec_nod(505,nod);
    scanf("%d %d %d %d",&n,&m,&s,&d);
    int a1,a2,cost_,dist_;
    for (int i=0;i<505;++i)
    {
      for(int j=0;j<=i;++j)
      {
        dst[i][j]=0x7fffffff;
        dst[j][i]=0x7fffffff;
      }
    }
    for (int i=0;i<m;++i)
    {
      scanf("%d %d %d %d",&a1,&a2,&dist_,&cost_);
      dst[a1][a2]=dist_;
      dst[a2][a1]=dist_;
      cst[a1][a2]=cost_;
      cst[a2][a1]=cost_;
    }
    vector<int> dt(505,0x7fffffff);
    dt[s]=0;
    vec_nod[s].cost=0;
    vec_nod[s].dist=0;
    vec_nod[s].vec_path.push_back(s);
    for (int i=0;i<n-1;++i)
    {
      vector<int>::iterator it=min_element(dt.begin(),dt.end());
      int idx=it-dt.begin();
      for (int j=0;j<n;++j)
      {
        if (dst[idx][j]==0x7fffffff)
        {
          continue;
        }
        if (vec_nod[idx].dist+dst[idx][j]<vec_nod[j].dist || vec_nod[idx].dist+dst[idx][j]==vec_nod[j].dist && vec_nod[idx].cost+cst[idx][j]<vec_nod[j].cost)
        {
          
          vec_nod[j].dist=vec_nod[idx].dist+dst[idx][j];
          dt[j]=vec_nod[j].dist;
          vec_nod[j].cost=vec_nod[idx].cost+cst[idx][j];
          vec_nod[j].vec_path=vec_nod[idx].vec_path;
          vec_nod[j].vec_path.push_back(j);
        }
      }
      dt[idx]=0x7fffffff;
    }
    for (int i=0;i<vec_nod[d].vec_path.size();++i)
    {
      printf("%d ",vec_nod[d].vec_path[i]);
    }
    printf("%d %d\n",vec_nod[d].dist,vec_nod[d].cost);
  }
  system("pause");
  return 0;
}