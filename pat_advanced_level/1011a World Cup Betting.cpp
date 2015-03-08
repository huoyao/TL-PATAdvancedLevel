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
  double w,t,l;
  double sum=1.f;
  char c[4];
  for (int i=0;i!=3;++i)
  {
    scanf("%lf %lf %lf",&w,&t,&l);
    double max_elem=max(l,max(w,t));
    sum*=max_elem;
    if (abs(max_elem-w)<1e-7)
    {
      c[i]='W';
    }else if (abs(max_elem-t)<1e-7)
    {
      c[i]='T';
    }else
    {
      c[i]='L';
    }
  }
  double resutl=(sum*0.65f-1.0f)*2.f;
 resutl+=0.005f;
  printf("%c %c %c %.2lf",c[0],c[1],c[2],resutl);
  system("pause");
  return 0;
}