#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a,long long b)
{
  for(long long t;t=a%b;a=b,b=t);
  return b;
}

void sim(long long &a,long long &b)
{
  long long gc=gcd(a<0?-a:a,b);
  a/=gc;b/=gc;
}

void fun(long long a,long long b)
{
  if(b==0) {printf("Inf");return;}
  if(b<0) {a=-a;b=-b;}
  sim(a,b);
  bool flag=false;
  if(a<0) {printf("(-");a=-a;flag=true;}
  if(a%b==0) printf("%lld",a/b);
  else if(a<b) printf("%lld/%lld",a,b);
  else printf("%lld %lld/%lld",a/b,a%b,b);
  if(flag) printf(")");
}

int main()
{
  long long a1,b1,a2,b2;
  scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
  fun(a1,b1);printf(" + ");fun(a2,b2);printf(" = ");fun(a1*b2+a2*b1,b1*b2);printf("\n");
  fun(a1,b1);printf(" - ");fun(a2,b2);printf(" = ");fun(a1*b2-a2*b1,b1*b2);printf("\n");
  fun(a1,b1);printf(" * ");fun(a2,b2);printf(" = ");fun(a1*a2,b1*b2);printf("\n");
  fun(a1,b1);printf(" / ");fun(a2,b2);printf(" = ");fun(a1*b2,b1*a2);printf("\n");
  return 0;
}