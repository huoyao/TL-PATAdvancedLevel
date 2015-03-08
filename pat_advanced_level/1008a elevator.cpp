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


int main()
{
  int n,floor_idx,floor_old;
  scanf("%d",&n);
  floor_old=0;
  int sum=0;
  for (int i=0;i!=n;++i)
  {
    scanf("%d",&floor_idx);
    if (floor_idx>floor_old)
    {
      sum+=((floor_idx-floor_old)*6);
    }else if (floor_idx<floor_old)
    {
      sum+=((floor_old-floor_idx)*4);
    }
    floor_old=floor_idx;
  }
  sum+=(n*5);
  printf("%d\n",sum);
  system("pause");
  return 0;
}