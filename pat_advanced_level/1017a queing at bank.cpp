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

struct tim
{
  int hh;
  int mm;
  int ss;
  int p_time;
  int arrive_time;
  int waiting_time;
};

bool cmp(const tim& t1,const tim &t2)
{
  if (t1.hh<t2.hh)
  {
    return true;
  }else if (t1.hh==t2.hh)
  {
    if (t1.mm<t2.mm)
    {
      return true;
    }else if (t1.mm==t2.mm)
    {
      if (t1.ss<t2.ss)
      {
        return true;
      }else
      {
        return false;
      }
    }else
    {
      return false;
    }
  }else
  {
    return false;
  }
}

int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  if (n<=0 || k<=0)
  {
    printf("0.0");
    return 0;
  }
  vector<tim> vec_persion;
  while(n--)
  {
    int h,m,s,p;
    int w_time=0;
    scanf("%d:%d:%d %d",&h,&m,&s,&p);
    if (p>60)
    {
      p=60;
    }
    if (h<17 || (h==17 && m==0 &&s==0))
    {
      tim ti;
      ti.hh=h;
      ti.mm=m;
      ti.ss=s;
      ti.p_time=p*60;
      //mark
      if (h<8)
      {
        w_time=(7-h)*3600+(59-m)*60+(60-s);
        h=8;
        m=0;
        s=0;
      }
      ti.waiting_time=w_time;
      ti.arrive_time=(h-8)*3600+m*60+s;
      vec_persion.push_back(ti);
    }
  }
  if (vec_persion.size()==0)
  {
    printf("0.0");
    return 0;
  }
  sort(vec_persion.begin(),vec_persion.end(),cmp);
  vector<int> waiting(k,0);
  int all_time=0;
  for (vector<tim>::iterator it=vec_persion.begin();it!=vec_persion.end();++it)
  {
   vector<int>::iterator idx=min_element(waiting.begin(),waiting.end());
   if (it->arrive_time>=*idx)
   {
     *idx=it->arrive_time+it->p_time;
   }else
   {
     all_time+=(*idx-it->arrive_time);
     *idx+=it->p_time;
   }
   all_time+=it->waiting_time;
  }
  double muni=all_time/60.f;
  muni/=vec_persion.size();
  printf("%.1f",muni);
  system("pause");
  return 0;
}