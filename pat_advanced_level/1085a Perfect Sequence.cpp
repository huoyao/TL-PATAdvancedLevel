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
    long long p;
    scanf("%d %lld",&n,&p);
    vector<long long> vec_in(n);
    for (int i=0;i<n;++i)
    {
      scanf("%lld",&vec_in[i]);
    }
    sort(vec_in.begin(),vec_in.end());
    int cnt=0,max_=0;
    for (int i=0;i<n;++i)
    {
      while(cnt<n && vec_in[cnt]<=vec_in[i]*p) ++cnt;
      if (max_<(cnt-i))
      {
        max_=cnt-i;
      }
      if (cnt>=n)
      {
        break;
      }
    }
    printf("%d\n",max_);
  }
  system("pause");
  return 0;
}