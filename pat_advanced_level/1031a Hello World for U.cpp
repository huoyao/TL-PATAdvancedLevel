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
  //while(1)
  {
    string str;
    cin>>str;
    int len=str.size();
    int n1=(len+2)/3;
    int n2=len-n1*2;
    for (int i=1;i<n1;++i)
    {
      printf("%c",str[i-1]);
      for (int j=0;j<n2;++j)
      {
        printf(" ");
      }
      printf("%c\n",str[len-i]);
    }
    n2+=2;
    for (int i=0;i<n2;++i)
    {
      printf("%c",str[n1+i-1]);
    }
  }
  system("pause");
  return 0;
}