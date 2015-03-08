#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

struct player
{
  int arriving_t;
  int serving_t;
  int waiting_t;
  int vip;
};

bool cmp(const player &p1,const player &p2)
{
  return p1.arriving_t<p2.arriving_t;
}

void timing(vector<int> &vec_time,set<int> &vip_table,int &min_vip,int &min_novip,int &min_vip_id,int &min_novip_id,int tt)
{
  min_vip=0x7fffffff;
  min_novip=0x7fffffff;
  bool f1=true,f2=true;
  for (int i=0;i<vec_time.size();++i)
  {
    
    if (vec_time[i]<min_novip && f1)   
    {
      min_novip=vec_time[i];
      min_novip_id=i;
    }
    if (vec_time[i]-tt<=0 && f1)  //mark
    {
      f1=false;
    }
    if (vip_table.find(i)!=vip_table.end())
    {
      if (vec_time[i]<min_vip && f2)
      {
        min_vip=vec_time[i];
        min_vip_id=i;
      }
      if (vec_time[i]-tt<=0 && f2)  //mark
      {
        f2=false;
      }
    }
    
  }
  if (min_vip==0x7fffffff)
  {
    min_vip=min_novip;
    min_vip_id=min_novip_id;
  }
}

void change(int &vip_idx,int &min_novip_id,vector<player> &vip_p,vector<int> &vec_table,vector<int> &time,bool &pt)
{
  if (time[min_novip_id]>=46800)
  {
    return ;
  }
  pt=false;
  int arr_t=vip_p[vip_idx].arriving_t;
  int ti=time[min_novip_id];
  int wait_t=arr_t<ti?(ti-arr_t):0;
  int h=arr_t/3600;
  int m=(arr_t-h*3600)/60;
  h+=8;
  int s=arr_t%60;
  wait_t+=arr_t;
  if (wait_t>=46800)
  {
    return;
  }
   printf("%02d:%02d:%02d ",h,m,s);
  h=wait_t/3600;
  m=(wait_t-h*3600)/60;
  h+=8;
  s=wait_t%60;
  printf("%02d:%02d:%02d ",h,m,s);
  wait_t-=arr_t;
  if (wait_t%60>=30)  //mark
  {
    wait_t/=60;
    wait_t++;
  }else{
    wait_t/=60;
  }
  printf("%d\n",wait_t);
  ++vec_table[min_novip_id];
  if (vip_p[vip_idx].arriving_t<=time[min_novip_id])
  {
    time[min_novip_id]+=vip_p[vip_idx].serving_t;
  }else
  {
    time[min_novip_id]=vip_p[vip_idx].arriving_t+vip_p[vip_idx].serving_t;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<player> vip_p;
  vector<player> novip_p;
  bool print=true;
  for (int i=0;i<n;++i)
  {
    player p;
    int h,m,s;
    scanf("%d:%d:%d %d %d",&h,&m,&s,&p.serving_t,&p.vip);
    if (p.serving_t>120)
    {
      p.serving_t=120;
    }
    p.serving_t*=60;
    int ti=(h-8)*3600+m*60+s;
    p.arriving_t=ti;
    if (p.vip)
    {
      vip_p.push_back(p);
    }else
    {
      novip_p.push_back(p);
    }
  }
  int k,m;
  scanf("%d %d",&k,&m);
  set<int> vip_table;
  for (int i=0;i<m;++i)
  {
    int table;
    scanf("%d",&table);
    vip_table.insert(table-1);
  }
  if (n==0)
  {
    for (int i=0;i<k;++i)
    {
      printf("0");
    }
    return 0;
  }
  sort(vip_p.begin(),vip_p.end(),cmp);
  sort(novip_p.begin(),novip_p.end(),cmp);
  vector<int> vec_table(k,0);
  vector<int> vec_time(k,0);
  int min_vip,min_novip;
  int min_vip_id,min_novip_id;
  int vip_idx=0,novip_idx=0;
  while(vip_idx<vip_p.size() || novip_idx<novip_p.size())
  {
    //timing(vec_time,vip_table,min_vip,min_novip,min_vip_id,min_novip_id);
    int tt;
    int a_t,b_t;
    if (vip_idx<vip_p.size())
    {
      a_t=vip_p[vip_idx].arriving_t;
    }else{
      a_t=0x7fffffff;
    }
    if (novip_idx<novip_p.size())
    {
      b_t=novip_p[novip_idx].arriving_t;
    }else{
      b_t=0x7fffffff;
    }
    if (a_t<b_t)
    {
      timing(vec_time,vip_table,min_vip,min_novip,min_vip_id,min_novip_id,a_t);
      if (a_t<min_vip)
      {
        tt=1;
      }else
      {
        tt=2;
      }
    }else
    {
      timing(vec_time,vip_table,min_vip,min_novip,min_vip_id,min_novip_id,b_t);
      if (a_t!=0x7ffffff && (a_t<=min_vip && min_vip==min_novip))
      {
        tt=2;
      }else{
        tt=3;
      }
    }
    switch(tt)
    {
    case 1:
      change(vip_idx,min_novip_id,vip_p,vec_table,vec_time,print);
      ++vip_idx;
      break;
    case 2:
      change(vip_idx,min_vip_id,vip_p,vec_table,vec_time,print);
      ++vip_idx;
      break;
    case 3:
      change(novip_idx,min_novip_id,novip_p,vec_table,vec_time,print);
      ++novip_idx;
      break;
    default:
      break;
    }
  }
  for (int i=0;i<vec_table.size();++i)
  {
    if (i==0)
    {
      printf("%d",vec_table[i]);
    }else
    {
      printf(" %d",vec_table[i]);
    }
  }
  if (print)
  {
    for (int i=0;i<k;++i)
    {
      printf("0");
    }
    return 0;
  }
  system("pause");
  return 0;
}