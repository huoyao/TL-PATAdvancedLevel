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

bool isprime(const int &val)
{
  if (val==1)
  {
    return false;
  }
  if (val==2)
  {
    return true;
  }
  int sq=sqrt(val*1.0);
  for (int i=2;i<=sq+1;++i)
  {
    if (val%i==0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  //while(1)
  {
    int m,n;
    scanf("%d %d",&m,&n);
    while(!isprime(m))++m;
    vector<bool> vec_flag(m,false);
    for (int i=0;i<n;++i)
    {
      int t;
      scanf("%d",&t);
      int j=t%m;
      int idx=1;
      while(idx<m && vec_flag[j]==true)  //mark idx==m
      {
        j=(t+idx*idx)%m;
        idx++;
      }
      if (i!=0)
      {
        printf(" ");
      }
      if (idx==m) //mark
      {
        printf("-");
      }else
      {
        vec_flag[j]=true;
        printf("%d",j);
      }
    }
  }
  system("pause");
  return 0;
}