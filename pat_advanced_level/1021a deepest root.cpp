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

vector<int> vec_num[10005];
bool err=false;
int k_circle=0;
vector<bool> vec_visit(10005,false);
vector<int> vec_dep;
int dep;
int max_dep=0;

void dfs_circle(int idx,int father)
{
  if (vec_visit[idx]==false)
  {
    vec_visit[idx]=true;
  }else
  {
    err=true;
    return ;
  }
  for (int i=0;i<vec_num[idx].size();++i)
  {
    if (vec_num[idx][i]==father)
    {
      continue;
    }
    dfs_circle(vec_num[idx][i],idx);
  }
}

void dfs_dep(int idx,int father)
{
  ++dep;
  if (dep>max_dep)
  {
    max_dep=dep;
  }
  for (int i=0;i<vec_num[idx].size();++i)
  {
    if (vec_num[idx][i]==father)  //mark
    {
      continue;
    }
    dfs_dep(vec_num[idx][i],idx);
    --dep;
  }
};

int main()
{
  int n;
  scanf("%d",&n);
  for (int i=1;i<n;++i)
  {
    int k,t;
    scanf("%d %d",&k,&t);
    vec_num[k].push_back(t);
    vec_num[t].push_back(k);
  }
  for (int i=1;i<=n;++i)
  {
    if (!vec_visit[i])
    {
      dfs_circle(i,0);
      ++k_circle;
    }
  }
  if (err || k_circle>1)
  {
    printf("Error: %d components\n",k_circle);
    return 0;
  }
  vec_dep.resize(n+1);
  vec_dep[0]=0;
  for (int i=1;i<=n;++i)
  {
    dep=0;
    max_dep=0;
    dfs_dep(i,0);
    vec_dep[i]=max_dep;
  }
  max_dep=0;
  vector<int> max_elem;
  for (int i=1;i<=n;++i)
  {
    if (vec_dep[i]>max_dep)
    {
      max_elem.clear();
      max_elem.push_back(i);
      max_dep=vec_dep[i];
    }else if (vec_dep[i]==max_dep)
    {
      max_elem.push_back(i);
    }
  }
  for (int i=0;i<max_elem.size();++i)
  {
    printf("%d\n",max_elem[i]);
  }
  system("pause");
  return 0;
}