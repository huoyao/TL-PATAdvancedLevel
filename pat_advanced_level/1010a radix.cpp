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
using namespace std;

void toDecimal(const char *n1,const int &n1_length,const long long &radix,long long &n1_decimal)
{
  n1_decimal=0;
  long long idx=1,num;
  for (int i=n1_length-1;i>=0;--i)
  {
    if (isdigit(n1[i]))
    {
      num=n1[i]-'0';
    }else
    {
      num=n1[i]-'a'+10;
    }
    n1_decimal+=num*idx;
    idx*=radix;
  }
}

//int cmp(const char *n1,const char *n2)
//{
//  int len1=strlen(n1);
//  int len2=strlen(n2);
//  if (len1>len2)
//  {
//    return 1;
//  }else if (len1<len2)
//  {
//    return -1;
//  }else
//  {
//    for (int i=len1-1;i>=0;--i)
//    {
//      if (n1[i]>n2[i])
//      {
//        return 1;
//      }else if (n1[i]<n2[i])
//      {
//        return -1;
//      }
//    }
//    return 0;
//  }
//}

int maxRadix(const char *n)
{
  int len=strlen(n);
  int max_num=0;
  int idx=0;
  while(n[idx]!='\0')
  {
    int temp;
    if (isdigit(n[idx]))
    {
      temp=n[idx]-'0';
      if (temp>max_num)
      {
        max_num=temp;
      }
    }else
    {
      temp=n[idx]-'a'+10;
      if (temp>max_num)
      {
        max_num=temp;
      }
    }
    ++idx;
  }
  return max_num;
}

int main()
{
  long long radix;
  int tag;
  char n1[12],n2[12];
  scanf("%s %s %d %lld",n1,n2,&tag,&radix);
  long long n1_decimal,n2_decimal;
  char temp[12];
  if (tag==2)
  {
    strcpy(temp,n2);
    strcpy(n2,n1);
    strcpy(n1,temp);
  }
  int n1_length=strlen(n1);
  int n2_length=strlen(n2);
  int max_radix=maxRadix(n2);
  toDecimal(n1,n1_length,radix,n1_decimal);
  toDecimal(n2,n2_length,radix,n2_decimal);
  if (n1_decimal==n2_decimal && max_radix<radix)
  {
    printf("%lld\n",radix);
    return 0;
  }
  long long max_idx=(n1_decimal+1>max_radix+1)?n1_decimal+1:max_radix+1;

  long long low_idx=max_radix+1;
  long long up_idx=max_idx;
  long long mid=low_idx;
 
  while(low_idx<=up_idx)
  {
    n2_decimal=0;
    long long idx=1,num;
    int flag_maxmin=2;
    for (int i=n2_length-1;i>=0;--i)
    {
      if (isdigit(n2[i]))
      {
        num=n2[i]-'0';
      }else
      {
        num=n2[i]-'a'+10;
      }
      n2_decimal+=num*idx;
      idx*=mid;
      if (n2_decimal>n1_decimal)
      {
        flag_maxmin=1;
        break;
      }
    }
    if (flag_maxmin==1)
    {
      up_idx=mid-1;
      mid=(low_idx+up_idx)/2;
    }else
    {
      if (n1_decimal==n2_decimal)
      {
        printf("%lld\n",mid);
        return 0;
      }else
      {
        low_idx=mid+1;
        mid=(low_idx+up_idx)/2;
      }
    }
  }
  printf("Impossible\n");
  system("pause");
  return 0;
}