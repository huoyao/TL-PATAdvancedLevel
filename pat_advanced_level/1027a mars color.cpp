#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <limits>

using namespace std;

void tomar(int &t)
{
  map<int,char> map_num;
  map_num[10]='A';
  map_num[11]='B';
  map_num[12]='C';

  int re=t%13;
  int k=0;
  t/=13;
  while(t)
  {
    k=t%13;
    t/=13;
  }
  if (k>9)
  {
    printf("%c",map_num[k]);
  }else
  {
    printf("%d",k);
  }
  if (re>9)
  {
    printf("%c",map_num[re]);
  }else
  {
    printf("%d",re);
  }
}

int main()
{
  int a,b,c;
  int t1,t2;

  scanf("%d %d %d",&a,&b,&c);
  printf("#");
  tomar(a);
  tomar(b);
  tomar(c);
  system("pause");
  return 0;
}