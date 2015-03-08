#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <map>
using namespace std;

int main()
{
  int k,nk;
  double ki;
  map<int,double> map_moly;
  map<int,double> map_result;
  scanf("%d",&k);
  while(k)
  {
    scanf("%d%lf",&nk,&ki);
    map_moly[nk]=ki;
    --k;
  }
  int t;
  scanf("%d",&t);
  while(t)
  {
    scanf("%d%lf",&nk,&ki);
    for (map<int,double>::iterator it=map_moly.begin();it!=map_moly.end();++it)
    {
      int ex;
      double coff;
      ex=nk+it->first;
      coff=ki*it->second;

      if (map_result.find(ex)==map_result.end())
      {
        map_result[ex]=coff;
      }else
      {
        map_result[ex]+=coff;
      }
    }
    --t;
  }
  int cnt=0;
  for (map<int ,double>::const_reverse_iterator crit=map_result.crbegin();crit!=map_result.crend();++crit)
  {
    if (abs(crit->second)>1e-2)
    {
      ++cnt;
    }
  }
  printf("%d",cnt);
  for (map<int ,double>::const_reverse_iterator crit=map_result.crbegin();crit!=map_result.crend();++crit)
  {
    if (abs(crit->second)>1e-2)
    {
      printf(" %d %.1lf",crit->first,crit->second);
    }
  }
  system("pause");
  return 0;
}