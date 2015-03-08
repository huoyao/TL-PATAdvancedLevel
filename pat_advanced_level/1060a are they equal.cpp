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
    int n;
    char integer1[101],deci1[101],integer2[101],deci2[101];
    scanf("%d",&n);
    char c;
    scanf("%*c%c",&c);
    while (c=='0')
    {
      scanf("%c",&c);
    }
    int cnt1=0;
    while(c!='.' && c!=' ')
    {
      integer1[cnt1++]=c;
      scanf("%c",&c);
    }
    int cnt2=0;
    if (c=='.')
    {
      scanf("%c",&c);
      while(c!=' ')
      {
        deci1[cnt2++]=c;
        scanf("%c",&c);
      }
    }
    scanf("%c",&c);
    while (c=='0')
    {
      scanf("%c",&c);
    }
    int cnt3=0;
    while(c!='.' && c!='\n')
    {
      integer2[cnt3++]=c;
      scanf("%c",&c);
    }
    int cnt4=0;
    if (c=='.')
    {
      scanf("%c",&c);
      while(c!='\n')
      {
        deci2[cnt4++]=c;
        scanf("%c",&c);
      }
    }
    if (n<=0)
    {
      printf("YES 0.0*10^0 0.0*10^0\n");
      return 0;
    }
    char re1[101],re2[101];
    int idx1=0,idx2=0;
    int i=0;
    for (;i<n && i<cnt1;++i)
    {
      re1[i]=integer1[i];
    }
    int idx=0;
    for (;i<n && i<cnt1+cnt2 && idx<cnt2;++i)
    {
      if (i==0)
      {
        while(deci1[idx]=='0')
        {
          ++idx;
          --cnt1;
        }
        if (idx==cnt2)
        {
          cnt1=0;
          re1[i++]='0';
          break;
        }
      }
      re1[i]=deci1[idx++];
    }
    while (i<n)
    {
      re1[i++]='0';
    }
    re1[i]='\0';
    i=0;
    bool eq=true;
    for (;i<n && i<cnt3;++i)
    {
      re2[i]=integer2[i];
      if (re2[i]!=re1[i])
      {
        eq=false;
      }
    }
    idx=0;
    for (;i<n && i<cnt3+cnt4;++i)
    {
      if (i==0)
      {
        while(deci2[idx]=='0')
        {
          ++idx;
          --cnt3;
        }
        if (idx==cnt4)
        {
          cnt3=0;
          re2[i++]='0';
          break;
        }
      }
      re2[i]=deci2[idx++];
      if (re2[i]!=re1[i])
      {
        eq=false;
      }
    }
    while (i<n)
    {
      re2[i]='0';
      if (re2[i]!=re1[i])
      {
        eq=false;
      }
      ++i;
    }
    re2[i]='\0';
    if (eq && cnt1==cnt3)
    {
      printf("YES 0.%s\*10\^%d",re1,cnt1);
    }else
    {
      printf("NO 0.%s\*10\^%d 0.%s\*10\^%d\n",re1,cnt1,re2,cnt3);
    }
  }
  system("pause");
  return 0;
}