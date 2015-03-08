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
  long long n,b;
  scanf("%lld %lld",&n,&b);
  if (n==0)
  {
    printf("Yes\n");
    printf("0\n");
    return 0;
  }
  long long num;
  vector<long long> vec_num;
  long long k=n%b;
  vec_num.push_back(k);
  num=n/b;
  while(num)
  {
    k=num%b;
    vec_num.push_back(k);
    num/=b;
  }
  bool flag=true;
  for (int i=0,j=vec_num.size()-1;i<j;++i,--j)
  {
    if (vec_num[i]!=vec_num[j])
    {
      flag=false;
      break;
    }
  }
  if (flag)
  {
    printf("Yes\n");
  }else
  {
    printf("No\n");
  }
  for (int i=vec_num.size()-1;i>=0;--i)
  {
    if (i==0)
    {
      printf("%lld",vec_num[i]);
    }else
    {
      printf("%lld ",vec_num[i]);
    }
  }
  printf("\n");
  system("pause");
  return 0;
}