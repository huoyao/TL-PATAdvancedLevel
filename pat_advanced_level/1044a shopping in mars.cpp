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

struct st
{
  int first,second,m;
};

bool cmp(const st&s1,const st&s2)
{
  //return s1.m<s2.m;
  if (s1.m!=s2.m)
  {
    return s1.m<s2.m;
  }else
  {
    return true;
  }
}

int main()
{
  //while(1)
  {
    int n,m;
    scanf("%d %d",&n,&m);
    if (n==0)
    {
      return 0;
    }
    vector<int> vec_in(n+1);
    for (int i=1;i<=n;++i)
    {
      scanf("%d",&vec_in[i]);
    }
    vec_in[0]=0;
    int j=1;
    int mt=vec_in[1],mc=mt-m;
    int min_mc=0x7fffffff;
    vector<st> vec_st;
    for (int i=1;i<=n && j<=n;++i)
    {
      mt-=vec_in[i-1];
      mc=mt-m;
      while(mc<0)
      {
        ++j;
        if (j>n)
        {
          j=n;
          break;
        }
        mt+=vec_in[j];
        mc=mt-m;
      }
      if (mc>=0 && mc<=min_mc)
      {
        min_mc=mc;
        st stt;
        stt.first=i;
        stt.second=j;
        stt.m=mt;
        vec_st.push_back(stt);
      } 
    }
    sort(vec_st.begin(),vec_st.end(),cmp);
    mt=min_mc+m;
    for (int i=0;i<vec_st.size();++i)
    {
      if (vec_st[i].m==mt)
      {
        printf("%d-%d\n",vec_st[i].first,vec_st[i].second);
      }
    }
  }
  system("pause");
  return 0;
}