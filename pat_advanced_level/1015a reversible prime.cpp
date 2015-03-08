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


long long toDecilReverse(long long &in_c,const int &d)
{
  vector<int> vec_num;
  int remain=in_c%d;
  long long rem=in_c/d;
  vec_num.push_back(remain);
  while(rem)
  {
    remain=rem%d;
    rem=rem/d;
    vec_num.push_back(remain);
  }
  long long cnt=1;
  long long out_put=0;
  for (vector<int>::const_reverse_iterator crit=vec_num.crbegin();crit!=vec_num.crend();++crit)
  {
    out_put+=((*crit)*cnt);
    cnt*=d;
  }
  return out_put;
}

bool isPrime(const long long &l)
{
  long long t=static_cast<long long>(sqrt(l*1.f));
  for(long long i=2;i<=t+1;++i)
  {
    if (l%i==0 && l!=2)
    {
      return false;
    }
  }
  return true;
}

void toPrime(bool *prime,const long long &n)
{
  for (long long i=0;i!=n;++i)
  {
    prime[i]=true;
  }
  prime[0]=false;
  prime[1]=false;
  for (long long i=2;i!=n;++i)
  {
    if (prime[i])
    {
      if(isPrime(i))
      {
        long long cnt=i*2;
        for (long long j=3;cnt<n;++j)
        {
          prime[cnt]=false;
          cnt=j*i;
        }
      }
    }
  }
}

int main()
{
  int d;
  bool prime[500001];
  long long in_num;
  scanf("%lld",&in_num);
  long long n_reverse;
  toPrime(prime,500001);
  while(in_num>=0)
  {
    scanf("%d",&d);
    if (prime[in_num])
    {
      n_reverse=toDecilReverse(in_num,d);
    }
    
    if (prime[in_num] && prime[n_reverse])
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
    scanf("%lld",&in_num);
  }
  system("pause");
  return 0;
}