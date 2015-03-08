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

struct nd
{
  int addr;
  int val;
  int next_add;
};

bool cmp(const nd &n1,const nd &n2)
{
  return n1.val<n2.val;
}

int main()
{
  //while(1)
  {
    int n,start_add;
    scanf("%d %d",&n,&start_add);
    nd d;
    d.addr=-1;
    d.val=0;
    d.next_add=-1;
    vector<nd> vec_nd(100000,d);  //mark d
    for (int i=0;i<n;++i)
    {
      nd in_node;
      scanf("%d %d %d",&in_node.addr,&in_node.val,&in_node.next_add);
      vec_nd[in_node.addr]=in_node;
    }
    if (start_add==-1)  //mark
    {
      printf("0 %d\n",start_add);
      return 0;
    }
    if (vec_nd[start_add].addr==-1)  //mark
    {
      printf("0 %05d\n",start_add);
      return 0;
    }
    nd in_nd=vec_nd[start_add];
    vector<nd> vec_re;
    while(in_nd.next_add!=-1)
    {
      vec_re.push_back(in_nd);
      in_nd=vec_nd[in_nd.next_add];
    }
    vec_re.push_back(in_nd);
    sort(vec_re.begin(),vec_re.end(),cmp);
    printf("%d %05d\n",vec_re.size(),vec_re[0].addr);
    int i=0;
    for (;i<vec_re.size()-1;++i)
    {
      printf("%05d %d %05d\n",vec_re[i].addr,vec_re[i].val,vec_re[i+1].addr);
    }
    printf("%05d %d -1\n",vec_re[i].addr,vec_re[i].val);
  }
  system("pause");
  return 0;
}