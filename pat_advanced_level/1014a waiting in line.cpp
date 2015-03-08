#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <queue>
using namespace std;

struct tt
{
  int h;
  int m;
};

tt formateTime(const int &t)
{
  int h=t/60;
  int m=t-h*60;
  tt tim;
  tim.h=h+8;
  tim.m=m;
  return tim;
}


int outTime(const int &n,const int &m,const int &time,queue<int> *vec_line,bool &flag)
{
  int leave_time=32766;
  int idx=vec_line[1].size();
  int ind=1;
  int ind_=1;
  for (int i=1;i<=n;++i)
  {
    if (!vec_line[i].empty())
    {
      if (vec_line[i].front()<leave_time)
      {
        leave_time=vec_line[i].front();
        ind_=i;
      }
    }
    if (vec_line[i].size()<m && vec_line[i].size()<idx)
    {
      idx=vec_line[i].size();
      ind=i;
      break;
    }
  }
  
  if (idx==m)
  {
    if (vec_line[ind_].back()>=540)
    {
      flag=true;
    }
    int tt=time+vec_line[ind_].back();
    vec_line[ind_].push(tt);
    vec_line[ind_].pop();
    return tt;
  }else
  {
    int tt=time;
    if (!vec_line[ind].empty())
    {
      tt+=vec_line[ind].back();
      if (vec_line[ind].back()>=540)
      {
        flag=true;
      }
    }
    vec_line[ind].push(tt);
    return tt;
  }
}

int main()
{
  int n,m,k,q;
  scanf("%d %d %d %d",&n,&m,&k,&q);
  queue<int> queue_line[21];
  vector<int> customer(k+1);
  int cnt=1;
  while(k--)
  {
    int time;
    scanf("%d",&time);
    bool flag=false;
    int result_time=outTime(n,m,time,queue_line,flag);
    if (!flag)
    {
      customer[cnt++]=result_time;
    }else
    {
      customer[cnt++]=-1;
    }
  }
  while(q--)
  {
    int query;
    scanf("%d",&query);
    if (customer[query]==-1)
    {
      printf("Sorry\n");
    }else
    {
      tt t=formateTime(customer[query]);
      printf("%02d:%02d\n",t.h,t.m);
    }
  }
  system("pause");
  return 0;
}