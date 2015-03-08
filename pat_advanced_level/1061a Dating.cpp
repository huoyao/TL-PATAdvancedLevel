#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <map>
using namespace std;


int main()
{
  //while(1)
  {
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int cnt=0;
    bool flag=true;
    map<int,string> map_nam;
    map_nam[1]="MON";
    map_nam[2]="TUE";
    map_nam[3]="WED";
    map_nam[4]="THU";
    map_nam[5]="FRI";
    map_nam[6]="SAT";
    map_nam[7]="SUN";
    while(cnt<str1.length() && cnt<str2.length())
    {
      if (str1[cnt]!=str2[cnt])
      {
        ++cnt;
      }else
      {
        if (flag)
        {
          if (isupper(str1[cnt]) && str1[cnt]-'A'<=6)
          {
            flag=false;
            printf("%s",map_nam[str1[cnt]-'A'+1].c_str());
          } 
        }else
        {
          if (isdigit(str1[cnt]))
          {
            printf(" %02d",str1[cnt]-'0');
            break;
          }else if (str1[cnt]>='A' &&str1[cnt]<='N' ) //mark for case 3  ¡¾A..N¡¿
          {
            printf(" %02d",str1[cnt]-'A'+10);
            break;
          }
        }
        ++cnt;
      }
    }
    cnt=0;
    while(cnt<str3.length() && cnt<str4.length())
    {
      if (str3[cnt]!=str4[cnt])
      {
        ++cnt;
      }else
      {
        if (isalpha(str3[cnt]))
        {
          printf(":%02d\n",cnt);
          break;
        }
        ++cnt;
      }
    }
  }
  system("pause");
  return 0;
}