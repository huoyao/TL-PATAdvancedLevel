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
  char c;
  vector<int> vec_origin(10,0);
  vector<int> vec_num;
  vector<int> vec_result(23,0);
  scanf("%c",&c);
  while(c!='\n')
  {
    int num=c-'0';
    ++vec_origin[num];
    vec_num.push_back(num);
    scanf("%c",&c);
  }
  if (vec_num.size()==1 && vec_num[0]==0)
  {
    printf("Yes\n");
    printf("0\n");
    return 0;
  }
  int cnt=0;
  for (int i=vec_num.size()-1;i>=0;--i)
  {
    int num=vec_num[i]*2;
    vec_result[cnt]+=num%10;
    vec_result[cnt+1]+=num/10;
    vec_origin[vec_result[cnt]]--;
    ++cnt;
  }
  int i;
  for (i=0;i<vec_origin.size();++i)
  {
    if (vec_origin[i]!=0)
    {
      printf("No\n");
      break;
    }
  }
  if (i==vec_origin.size())
  {
    printf("Yes\n");
  }
  if (vec_result[cnt]!=0)
  {
    printf("%d",vec_result[cnt]);
  }
  for (int j=cnt-1;j>=0;--j)
  {
    printf("%d",vec_result[j]);
  }
  printf("\n");
  system("pause");
  return 0;
}