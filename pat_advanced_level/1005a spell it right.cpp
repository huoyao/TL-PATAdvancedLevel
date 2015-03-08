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
  char c;
  scanf("%c",&c);
  int sum=0; 
  map<int,string> map_num;
  map_num[0]="zero";
  map_num[1]="one";
  map_num[2]="two";
  map_num[3]="three";
  map_num[4]="four";
  map_num[5]="five";
  map_num[6]="six";
  map_num[7]="seven";
  map_num[8]="eight";
  map_num[9]="nine";
  while(c!='\n')
  {
    sum+=c-'0';
    scanf("%c",&c);
  }
  int idx=sum/100;
  if (idx!=0)
  {
    printf("%s ",map_num[idx].c_str());
  }
  sum-=idx*100;
  int hun_idx=sum/10;
  if (idx!=0 || (idx==0 && hun_idx!=0))
  {
    printf("%s ",map_num[hun_idx].c_str());
  }
  sum-=hun_idx*10;
  idx=sum;
  printf("%s\n",map_num[idx].c_str());
  system("pause");
  return 0;
}