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

struct node
{
  vector<long> next;
};

int main()
{
  //while(1)
  {
    long a1,a2,n;
    scanf("%ld %ld %ld",&a1,&a2,&n);
    long d1,d2;
    vector<node> vec_nod(100005);
    for (long i=0;i<n;++i)
    {
      scanf("%ld %*c %ld",&d1,&d2);
      vec_nod[d1].next.push_back(d2);
    }
     long idx=a1;
     long len_a1=1,len_a2=1;
     if (a1==-1 || a2==-1) //mark!!!
     {
       printf("-1\n");
       return 0;
     }
    while(vec_nod[idx].next[0]!=-1)
    {
      idx=vec_nod[idx].next.front();
      ++len_a1;
    }
    idx=a2;
    while(vec_nod[idx].next[0]!=-1)
    {
      idx=vec_nod[idx].next.front();
      ++len_a2;
    }
    long idx_a1,idx_a2;
    if (len_a1>=len_a2)
    {
      idx_a1=a1;
      for (long i=0;i<len_a1-len_a2;++i)
      {
        idx_a1=vec_nod[idx_a1].next[0];
      }
      idx_a2=a2;
    }else{
      idx_a2=a2;
      for (long i=0;i<len_a2-len_a1;++i)
      {
        idx_a2=vec_nod[idx_a2].next[0];
      }
      idx_a1=a1;
    }
    long result_=1000000;
    while(idx_a1!=-1 && idx_a2!=-1)
    {
      if (idx_a1==idx_a2 && vec_nod[idx_a1].next.size()==1)
      {
        result_=idx_a1;
        break;
      }else if (idx_a1==idx_a2 && vec_nod[idx_a1].next.size()>=2)
      {
        idx_a1=vec_nod[idx_a1].next[0];
        idx_a2=vec_nod[idx_a1].next[1];
      }else
      {
        idx_a1=vec_nod[idx_a1].next[0];
        idx_a2=vec_nod[idx_a2].next[0];
      }
    }
    if (result_==1000000)
    {
      printf("-1\n");
    }else
    {
      printf("%05ld\n",result_);
    }
    
  }
  system("pause");
  return 0;
}