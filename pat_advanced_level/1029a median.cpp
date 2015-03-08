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
  while(1)
  {
    long n,m;
    scanf("%ld",&n);
    vector<long> vec_n(n);
    for (long i=0;i<n;++i)
    {
      scanf("%ld",&vec_n[i]);
    }
    scanf("%ld",&m);
    vector<long> vec_m(m);
    for (long i=0;i<m;++i)
    {
      scanf("%ld",&vec_m[i]);
    }
    long all=(n+m+1)/2;
    long cnt_n=0,cnt_m=0,cnt=0;
    while(cnt<=all)
    {
      if (cnt_n<vec_n.size() && cnt_m<vec_m.size())
      {
        if (vec_n[cnt_n]<vec_m[cnt_m])
        {
          ++cnt_n;
          ++cnt;
          if (cnt==all)
          {
            printf("%ld",vec_n[cnt_n-1]);
            return 0;
          }
        }else
        {
          ++cnt_m;
          ++cnt;
          if (cnt==all)
          {
            printf("%ld",vec_m[cnt_m-1]);
            return 0;
          }
        }
      }else
      {
        if (cnt_n==vec_n.size())
        {
          while(cnt<all)
          {
            ++cnt_m;
            ++cnt;
            if (cnt==all)
            {
              printf("%ld",vec_m[cnt_m-1]);
              return 0;
            }
          }
        }
        if (cnt_m==vec_m.size())
        {
          while(cnt<all)
          {
            ++cnt_n;
            ++cnt;
            if (cnt==all)
            {
              printf("%ld",vec_n[cnt_n-1]);
              return 0;
            }
          }
        }
      }

    }
  }
  system("pause");
  return 0;
}