#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;


int main()
{
  long a,b,c;
  scanf("%ld %ld",&a,&b);
  c=a+b;
  if (c<0)
  {
    printf("-");
    c=-c;
  }
   int hund=c/1000000;
  if (hund)
  {
    printf("%d,",hund);
  }
  c=c-hund*1000000;
  int thou=c/1000;
  if (hund || thou)
  {
    if (hund)
    {
      printf("%03d,",thou);
    }else
    {
      printf("%d,",thou);
    }
  }
  c=c-thou*1000;
  if (hund || thou)
  {
    printf("%03d",c);
  }else
  {
    printf("%d",c);
  }
  system("pause");
  return 0;
}