//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <cstdio>
//#include <cmath>
//#include <limits>
//using namespace std;
//
//void resize(vector<long long> &re,vector<long long> &rs)
//{
//  int i=0,j=rs.size()-1;
//  while(i<j)
//  {
//    int a=rs[i],b=rs[j];
//    if (a<b)
//    {
//      swap(a,b);
//    }
//    int idx=2;
//    int c=a;
//    while(c%b!=0)
//    {
//      c+=a;
//    }
//    re[i]=c;
//    ++i;
//    --j;
//  }
//  if (i==j)
//  {
//    re[i]=rs[i];
//  }
//}
//
//long long prime(const long long &a,const long long &b)
//{
//  if (a%b==0)
//  {
//    return b;
//  }
//  return prime(b,a%b);
//}
//
//int main()
//{
//  //while(1)
//  {
//    int n;
//    scanf("%d",&n);
//    vector<long long> num(n),denum(n);
//    for (int i=0;i<n;++i)
//    {
//      scanf("%lld/%lld",&num[i],&denum[i]);
//    }
//    vector<long long> re((n+1)/2);
//    int i=0,j=n-1;
//    vector<long long> rs=denum;
//    while(rs.size()>1)
//    {
//      resize(re,rs);
//      rs.clear();
//      rs.resize(re.size());
//      rs=re;
//      re.clear();
//      re.resize((rs.size()+1)/2);
//    }
//    long long up=0;
//    long long resul=rs[0];
//    for (int idx=0;idx<n;++idx)
//    {
//      up+=num[idx]*(resul/denum[idx]);
//    }
//    long long ing=up/resul;
//    up%=resul;
//    up=abs(up);
//    long long prim=prime(resul,up);
//    if (prim==0)
//    {
//      prim=1;
//    }
//    up/=prim;
//    resul/=prim;
//    if (ing!=0)
//    {
//      printf("%lld",ing);
//      if (up!=0)
//      {
//        printf(" %lld/%lld\n",up,resul);
//      }
//    }else
//    {
//      if (up!=0)
//      {
//        printf("%lld/%lld\n",up,resul);
//      }else
//      {
//        printf("0\n");
//      }
//    }
//  }
//  system("pause");
//  return 0;
//}
#include<cstdio>  
#include<iostream>  
#include<cmath>  
using namespace std;  
typedef long long ll;  
ll gcd(ll a,ll b){  
  for(int t;t=b;b=a%b,a=t);  
  return a;  
}  
ll aa,bb;  
int main(){  
  ll a,b,g;  
  int n;  
  aa=0,bb=1;  
  scanf("%d",&n);  
  while(n--){  
    scanf("%lld/%lld",&a,&b);  
    aa=aa*b+bb*a;  
    bb=bb*b;  
    g=gcd(labs(aa),labs(bb));  
    aa/=g;  
    bb/=g;   
  }  
  if(aa==0){  
    printf("0");  
  }  
  else{  
    if(aa/bb && aa%bb)printf("%lld %lld/%lld\n",aa/bb,aa%bb,bb);  
    else if(aa/bb){  
      printf("%lld\n",aa/bb);  
    }  
    else if(aa%bb){  
      printf("%lld/%lld\n",aa,bb);  
    }  

  }  
  return  0;  
}  