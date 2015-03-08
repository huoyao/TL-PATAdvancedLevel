#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;


int main()
{
  int n;
  scanf("%d",&n);
  map<int,float> map_exp;
  map<int,float> map_exp_result;
  int exponents;
  float coefficients;
  while(n--)
  {
    scanf("%d %f",&exponents,&coefficients);
    map_exp[exponents]=coefficients;
  }
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d %f",&exponents,&coefficients);
    if (map_exp.find(exponents)==map_exp.end())
    {
      map_exp[exponents]=coefficients;
    }else
    {
      map_exp[exponents]+=coefficients;
    }  
  }
  bool flag_first=false;
  bool flag_zero=false;
  for (map<int,float>::const_reverse_iterator crit=map_exp.crbegin();crit!=map_exp.crend();++crit)
  {
    if (abs(crit->second)>=1e-7)
    {
      map_exp_result[crit->first]=crit->second;
    }
  }
  for (map<int,float>::const_reverse_iterator crit=map_exp_result.crbegin();crit!=map_exp_result.crend();++crit)
  {
    //if (abs(crit->second)>=1e-7)
    {
      flag_zero=true;
      if (!flag_first)
      {
        printf("%d",map_exp_result.size());
        flag_first=!flag_first;
      }
      printf(" %d %.1f",crit->first,crit->second);
    }
  }
  if (!flag_zero)
  {
    printf("0\n");
  }
  system("pause");
  return 0;
}