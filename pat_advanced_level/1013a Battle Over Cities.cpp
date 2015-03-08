#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <queue>
#include <cstring>
using namespace std;

int cite[1001][1001];
int visited[1001];
int n,m,k;

void dfs(int idx)
{
  visited[idx]=1;
  for (int i=1;i<=n;++i)
  {
    if (visited[i]==0 && cite[idx][i]==1)
    {
      dfs(i);
    }
  }
}

int main()
{
  
  scanf("%d %d %d",&n,&m,&k);
  memset(cite,0,1001*1001*sizeof(int));
  
  while(m--)
  {
    int addr_a,addr_b;
    scanf("%d %d",&addr_a,&addr_b);
    cite[addr_a][addr_b]=1;
    cite[addr_b][addr_a]=1;
  }
  while(k--)
  {
    int t;
    scanf("%d",&t);
    memset(visited,0,1001*sizeof(int));
    visited[t]=1;
    int cnt=-1;
    for (int i=1;i<=n;++i)
    {
      if (!visited[i])
      {
        ++cnt;
        dfs(i);
      }
    }
    printf("%d\n",cnt);
  }
  system("pause");
  return 0;
}