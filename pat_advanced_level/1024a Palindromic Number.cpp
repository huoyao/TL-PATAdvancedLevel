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

bool unpal(vector<int> vec_a)
{
  vector<int> vec_b(vec_a);
  reverse(vec_b.begin(),vec_b.end());
  if (vec_a!=vec_b)
  {
    return true;
  }
  return false;
}


int main()
{
  char c;
  scanf("%c",&c);
  vector<int> vec_num;
  while(c!=' ')
  {
    int num=c-'0';
    vec_num.push_back(num);
    scanf("%c",&c);
  }
  int k;
  scanf("%d",&k);
  int cnt=0;
  while(unpal(vec_num) && cnt<k)
  {
    vector<int> vec_copy(vec_num);
    vec_num.clear();
    int up=0;
    for (int i=0,j=vec_copy.size()-1;i<vec_copy.size();++i,--j)
    {
      int n=vec_copy[i]+vec_copy[j];
      n+=up;    //mark
      vec_num.push_back(n%10);  //mark
      up=n/10;
    }
    if (up!=0)
    {
      vec_num.push_back(up);
    }
    ++cnt;
  }
  for (int i=vec_num.size()-1;i>=0;--i)
  {
    printf("%d",vec_num[i]);
  }
  printf("\n%d\n",cnt);
  system("pause");
  return 0;
}