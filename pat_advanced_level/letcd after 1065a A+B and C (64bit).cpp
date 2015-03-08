#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
  long long a,b,c,ans;
  int n;
  string ov;
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
  {
    scanf("%lld%lld%lld",&a,&b,&c);
    ans=a+b;
    printf("Case #%d: ",i);
    if(a>0 && b>0 && ans<=0) ov="true";
    else if(a<0 && b<0 && ans>=0) ov="false";
    else ov= ans>c?"true":"false";
    printf("%s\n",ov.c_str());   
  }
  return 0;
}