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

void maxSeq(int &idx_i,int &idx_j,vector<int> &vec_in,int &idx_min,int &idx_max,int &sum,const int &m)
{
  int temp_sum=0,temp_max=vec_in[idx_i];
  for (int i=idx_j;i!=m;++i)
  {
    temp_sum+=vec_in[i];
    if (temp_sum>temp_max)
    {
      idx_j=i;
      temp_max=temp_sum;
    }
    if (temp_sum<0)
    {
      break;
    }
  }
  if (temp_max>sum)
  {
    idx_min=vec_in[idx_i];
    idx_max=vec_in[idx_j];
    sum=temp_max;
  }
}

int main()
{
  int m;
  scanf("%d",&m);
  vector<int> vec_in(m);
  bool first=true;
  int idx_i,idx_min,idx_max,idx_j;
  int sum=0;
  int tem_sum=0;
  for (int i=0;i!=m;++i)
  {
    scanf("%d",&vec_in[i]);
    if (first && vec_in[i]>=0)
    {
      idx_i=i;
      idx_min=vec_in[i];
      idx_max=vec_in[i];
      idx_j=i;
      sum=vec_in[i];
      first=false;
    }
    if (!first && tem_sum>=0)
    {
       tem_sum+=vec_in[i];
    }
    if (tem_sum>sum)
    {
      idx_j=i;
      idx_max=vec_in[i];
      sum=tem_sum;
    }
  }
  if (first)
  {
    printf("%d %d %d\n",0,vec_in[0],vec_in[m-1]);
    return 0;
  }
  ++idx_j;
  while(idx_j!=m && vec_in[idx_j]==0)++idx_j;
  while(idx_j!=m && vec_in[idx_j]<0)++idx_j;
  idx_i=idx_j;
  while(idx_i!=m)
  {
    maxSeq(idx_i,idx_j,vec_in,idx_min,idx_max,sum,m);
    ++idx_j;
    while(idx_j!=m && vec_in[idx_j]==0)++idx_j;
    while(idx_j!=m && vec_in[idx_j]<0)++idx_j;
    idx_i=idx_j;
  }
  printf("%d %d %d\n",sum,idx_min,idx_max);
  system("pause");
  return 0;
}