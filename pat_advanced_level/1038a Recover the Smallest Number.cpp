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

bool cmp(const string &str1,const string&str2)
{
  if (str1.length()==str2.length())
  {
    return str1<=str2;
  }
  int i=0,j=0;
  int leg1=str1.length(),leg2=str2.length();
  if (str1.length()<str2.length())
  {
    string str2_(str2,j,leg1);
    while(str1==str2_)
    {
      j+=leg1;
      if (j+leg1>str2.length())
      {
        break;
      }
      str2_=string(str2,j,leg1);
    }
    int idx=0;
    while(j<str2.length())
    {
      idx%=str1.length();
      if (str1[idx]==str2[j])
      {
        ++idx;
        ++j;
      }else
      {
        return str1[idx]<str2[j];
      }
    }
    --j;
    idx%=str1.length();
    if (str2[j]>=str1[idx])
    {
      return true;
    }else
    {
      return false;
    }
  }else
  {
    string str2_(str1,i,leg2);
    while(str2==str2_)
    {
      i+=leg2;
      if (i+leg2>str1.length())
      {
        break;
      }
      str2_=string(str1,i,leg2);
    }
    int idx=0;
    while(i<str1.length())
    {
      idx%=str2.length();
      if (str1[i]==str2[idx])
      {
        ++idx;
        ++i;
      }else
      {
        return str1[i]<str2[idx];
      }     
    }
    --i;
    idx%=str2.length();
    if (str1[i]>=str2[idx])
    {
      return false;
    }else
    {
      return true;
    }
    
  }

 /* while(i<str1.length() && j<str2.length())
  {
    if (str1[i]==str2[j])
    {
      ++i;
      ++j;
    }else{
      return str1[i]<str2[j];
    }
  }
  if (i==str1.length())
  {
    int idx=0;
    while(j<str2.length())
    {
      idx%=str1.length();
      if (str1[idx]==str2[j])
      {
        ++idx;
        ++j;
      }else
      {
        return str1[idx]<str2[j];
      }
    }
  }else
  {
    int idx=0;
    while(i<str1.length())
    {
      idx%=str2.length();
      if (str1[i]==str2[idx])
      {
        ++idx;
        ++j;
      }else
      {
        return str1[i]<str2[idx];
      }
    }
  }*/
  return false;
}

int main()
{
  //while(1)
  {
    int n;
    cin>>n;
    vector<string> vec_str;
    for (int i=0;i<n;++i)
    {
      string str;
      cin>>str;
      vec_str.push_back(str);
    }
    sort(vec_str.begin(),vec_str.end(),cmp);
    string ss="";
    for (int i=0;i<vec_str.size();++i)
    {
      ss+=vec_str[i];
    }
    int i=0;
    while(ss[i]=='0')
    {
      ++i;
    }
    if(i<ss.length())
    {
      string sst(ss,i,ss.length()-i);
      printf("%s",sst.c_str());
    }else{
      printf("0");
    }
    printf("\n");
  }
  system("pause");
  return 0;
}