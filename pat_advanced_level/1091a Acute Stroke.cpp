#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int cnt=0,tmp=0,m,n,l,t;
int db[70][1300][130];
struct point
{
  int z,x,y;
  point(){}
  point(int a,int b,int c):x(a),y(b),z(c){}
};

void dfs_q(int i,int j,int k)
{
  queue<point> qu;
  qu.push(point(i,j,k));
  while(!qu.empty())
  {
    int a=qu.front().x,b=qu.front().y,c=qu.front().z;
    qu.pop();
    if(db[a][b][c])
    {
      ++tmp;
      db[a][b][c]=0;
      if(a>0) qu.push(point(a-1,b,c));
      if(a<l-1) qu.push(point(a+1,b,c));
      if(b>0) qu.push(point(a,b-1,c));
      if(b<m-1) qu.push(point(a,b+1,c));
      if(c>0) qu.push(point(a,b,c-1));
      if(c<n-1) qu.push(point(a,b,c+1));
    }
  }
}

int main()
{
  scanf("%d%d%d%d",&m,&n,&l,&t);
  for(int i=0;i<l;++i)
    for(int j=0;j<m;++j)
      for(int k=0;k<n;++k)
        scanf("%d",&db[i][j][k]);
  for(int i=0;i<l;++i)
    for(int j=0;j<m;++j)
      for(int k=0;k<n;++k)
        if(db[i][j][k]) {tmp=0;dfs_q(i,j,k);cnt+=tmp<t?0:tmp;}
  printf("%d",cnt);
  system("pause");
  return 0;
}