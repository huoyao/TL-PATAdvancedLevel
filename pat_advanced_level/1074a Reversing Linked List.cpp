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

struct lk
{
  int pre,next,val;
};


int main()
{
  //while(1)
  {
    int first_nod,n,k;
    scanf("%d %d %d",&first_nod,&n,&k);
    vector<lk> vec_in(100001);
    int pr,val,nt;
    for (int i=0;i<n;++i)
    {
      lk l;
      scanf("%d %d %d",&l.pre,&l.val,&l.next);
      vec_in[l.pre]=l;
    }
    if (first_nod==-1)
    {
      printf("-1\n");
      return 0;
    }
    vector<lk> vec_out;
    vec_out.push_back(vec_in[first_nod]);
    int id=0;
    while(vec_out[id].next!=-1)
    {
      lk l=vec_in[vec_out[id].next];
      vec_out.push_back(l);
      id++;
    }
    int idx=k-1;
    int i=idx;
    for (;i<vec_out.size();)
    {
      if (idx==0)
      {
        break;
      }
      int j=i-k+1;
      while(j<i)
      {
        lk l=vec_out[i];
        vec_out[i]=vec_out[j];
        vec_out[j]=l;
        ++j;
        --i;
      }
      idx+=k;
      i=idx;
    }
    i=0;
    for (;i<vec_out.size()-1;++i)
    {
      printf("%05d %d %05d\n",vec_out[i].pre,vec_out[i].val,vec_out[i+1].pre);
    }
    printf("%05d %d -1\n",vec_out[i].pre,vec_out[i].val);
  }
  system("pause");
  return 0;
}