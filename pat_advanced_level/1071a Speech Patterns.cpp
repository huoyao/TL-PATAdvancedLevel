#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

char c[1048600];
unordered_map<string,int> map;

int main()
{
  string res,str;
  int cnt=0,i=0;
  gets(c);
  while(c[i])
  {
    while(isalnum(c[i])) str+=tolower(c[i++]);
    if(!str.empty())
    {
      ++map[str];
      if(map[str]>cnt || (map[str]==cnt && str<res)) {res=str; cnt=map[str];}
      str.clear();
    }
    ++i;
  }
  printf("%s %d\n",res.c_str(),cnt);
  system("pause");
  return 0;
}