#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

struct node
{
  int max_rescue_team;
  int rescue_team;
  int short_dist;
  int short_path_num;
  map<int,int> adj_node;
  bool visited;
};

int maxElemt(const vector<node> &vec_node)
{
  int maxElement=0x7FFFFFFF;
  int index_need=0;
  for (vector<node>::const_iterator cit=vec_node.cbegin();cit!=vec_node.cend();++cit)
  {
    if (!cit->visited && cit->short_dist<=maxElement)
    {
      index_need=cit-vec_node.cbegin();
      maxElement=cit->short_dist;
    }
  }
  return index_need;
}

int main()
{
  int n,m,c1,c2;
  scanf("%d %d %d %d",&n,&m,&c1,&c2);
  vector<node> vec_node(n);
  for (int i=0;i!=n;++i)
  {
    scanf("%d",&vec_node[i].rescue_team);
    vec_node[i].short_dist=0x7FFFFFFF;
    vec_node[i].short_path_num=1;
    vec_node[i].visited=false;
    vec_node[i].max_rescue_team=0;
  }
  int d1,d2,dist;
  for (int i=0;i!=m;++i)
  {
    scanf("%d %d %d",&d1,&d2,&dist);
    vec_node[d1].adj_node[d2]=dist;
    vec_node[d2].adj_node[d1]=dist;
  }
  vec_node[c1].short_dist=0;
  vec_node[c1].max_rescue_team=vec_node[c1].rescue_team;
  int index_node=c1;
  while(--n)
  {
    if (!vec_node[index_node].visited)
    {
      for (map<int ,int>::const_iterator cit=vec_node[index_node].adj_node.cbegin();cit!=vec_node[index_node].adj_node.cend();++cit)
      {
        if (vec_node[index_node].short_dist+cit->second<vec_node[cit->first].short_dist)
        {
          vec_node[cit->first].short_dist=vec_node[index_node].short_dist+cit->second;
          vec_node[cit->first].short_path_num=vec_node[index_node].short_path_num;
          vec_node[cit->first].max_rescue_team=vec_node[cit->first].rescue_team+vec_node[index_node].max_rescue_team;
        }else if (vec_node[index_node].short_dist+cit->second==vec_node[cit->first].short_dist)
        {
          vec_node[cit->first].short_path_num+=vec_node[index_node].short_path_num;
          if (vec_node[cit->first].max_rescue_team<vec_node[cit->first].rescue_team+vec_node[index_node].max_rescue_team)
          {
            vec_node[cit->first].max_rescue_team=vec_node[cit->first].rescue_team+vec_node[index_node].max_rescue_team;
          }
        }
      }
      vec_node[index_node].visited=true;
      index_node=maxElemt(vec_node);
    }
  }
  printf("%d %d\n",vec_node[c2].short_path_num,vec_node[c2].max_rescue_team);
  system("pause");
  return 0;
}