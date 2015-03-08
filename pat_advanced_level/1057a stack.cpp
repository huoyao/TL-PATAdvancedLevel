#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <stack>
#include <map>
#include <vector>
using namespace std;

vector<int> arr_a(100001,0);

void update(const int &val,const int &idx)
{
  int i=val;
  while(i<=100000)
  {
    arr_a[i]+=idx;
    i+=i&(-i);
  }
}

int getsum(const int &val)
{
  int sum=0;
  int i=val;
  while(i>0)
  {
    sum+=arr_a[i];
    i-=i&(-i);
  }
  return sum;
}

int mid(const int&cnt,const int &l=0,const int &r=100000)
{
  if (l==r)
  {
    return l;
  }
  int md=(l+r)/2;
  if (getsum(md)<cnt)
  {
    return mid(cnt,md+1,r);
  }else
  {
    return mid(cnt,l,md);
  }
}

int main()
{
  //while(1)
  {
    int n;
    scanf("%d",&n);
    stack<int> stack_in;
    map<string,int> map_in;
    map_in[string("Pop")]=0;
    map_in[string("PeekMedian")]=1;
    map_in[string("Push")]=2;
    for (int i=0;i<n;++i)
    {
      char cc[11];
      scanf("%s",cc);
      string str(cc);
      switch(map_in[str])
      {
      case 0:
        if (stack_in.empty())
        {
          printf("Invalid\n");
          break;
        }else
        {
          printf("%d\n",stack_in.top());
          update(stack_in.top(),-1);
          stack_in.pop();
          break;
        }
        break;
      case 1:
        if (stack_in.empty())
        {
          printf("Invalid\n");
          break;
        }else
        {
          int cnt=(stack_in.size()+1)/2;
          printf("%d\n",mid(cnt));
          break;
        }
        break;
      case 2:
        int t;
        scanf("%d",&t);
        update(t,1);
        stack_in.push(t);
        break;
      default:
        break;
      }
    }
  }
  system("pause");
  return 0;
}