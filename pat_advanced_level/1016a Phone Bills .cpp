#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <limits>
using namespace std;

struct tim
{
  int month;
  int dd;
  int mm;
  int hh;
  char on_line[10];
};

struct phone
{
  char name[25];
  vector<tim> time;
  vector<tim> result_time;
};

bool cmp(const tim &a,const tim &b)
{
  if (a.month==b.month)
  {
    if (a.dd==b.dd)
    {
      if (a.hh==b.hh)
      {
        return a.mm<b.mm;
      }else
      {
        return a.hh<b.hh;
      }
    }else
    {
      return a.dd<b.dd;
    }  
  }else
  {
    return a.month<b.month;
  }
}

void compute(tim &a,tim &b,map<int,int> &rate,int &last_time,int &cost,int &one_cost)
{
  last_time=0;
  cost=0;
  if (a.dd!=b.dd)
  {
      last_time+=((23-a.hh+b.hh)*60+(60-a.mm+b.mm));
      cost+=(rate[a.hh]*(60-a.mm)+rate[b.hh]*b.mm);
      for (int i=a.hh+1;i<24;++i)
      {
        cost+=(rate[i]*60);
      }
      for (int i=0;i<b.hh;++i)
      {
        cost+=(rate[i]*60);
      }
      last_time+=(b.dd-a.dd-1)*24*60;
      cost+=(b.dd-a.dd-1)*one_cost;
  }else
  {
    last_time+=((b.hh-a.hh-1)*60+(60-a.mm+b.mm));
    if (a.hh!=b.hh)
    {
      cost+=(rate[a.hh]*(60-a.mm)+rate[b.hh]*b.mm);
      for (int i=a.hh+1;i<b.hh;++i)
      {
        cost+=(rate[i]*60);
      }
    }else
    {
      cost+=(b.mm-a.mm)*rate[a.hh];
    }
  }
}

bool cmp1(const phone &pha,const phone &phb)
{
  if (strcmp(pha.name,phb.name)<0)   //mark!!!!!!!!!!
  {
    return true;
  }else
  {
    return false;
  }
}

void deletDuplicate(phone &ph)
{
  for (vector<tim>::iterator cit=ph.time.begin();cit!=ph.time.end();++cit)
  {
    if ((ph.time.end()-cit)>1)
    {
      if (cit->on_line[1]=='n' && (cit+1)->on_line[1]=='f' &&cit->month==(cit+1)->month)
      {
        ph.result_time.push_back(*cit);
        ++cit;
        ph.result_time.push_back(*cit);
      }
    }
  }
}

int main()
{
  map<int,int> rate;
  int one_cost=0;
  for (int i=0;i<24;++i)
  {
    int temp;
    scanf("%d",&temp);
    one_cost+=temp;
    rate[i]=temp;
  }
  one_cost*=60;
  int n;
  scanf("%d",&n);
  int cnt=0;
  map<string,int> map_name;
  vector<phone> vec_ph;
  while(n--)
  {
    char nam[25];
    int mon;
    int d;
    int m;
    int h;
    char flag[10];
    scanf("%s %d:%d:%d:%d %s",nam,&mon,&d,&h,&m,flag);
    string str(nam);
    if (map_name.find(str)==map_name.end())
    {
      phone ph;
      strcpy(ph.name,nam);
      tim ti;
      ti.month=mon;
      ti.dd=d;
      ti.hh=h;
      ti.mm=m;
      strcpy(ti.on_line,flag);
      ph.time.push_back(ti);
      vec_ph.push_back(ph);
      map_name[str]=cnt;
      ++cnt;
    }else
    {
      tim ti;
      ti.month=mon;
      ti.dd=d;
      ti.hh=h;
      ti.mm=m;
      strcpy(ti.on_line,flag);
      vec_ph[map_name[str]].time.push_back(ti);
    }
  }
  
  for (vector<phone>::iterator it=vec_ph.begin();it!=vec_ph.end();++it)
  {
    sort(it->time.begin(),it->time.end(),cmp);
    deletDuplicate(*it);
  }

  sort(vec_ph.begin(),vec_ph.end(),cmp1);

  for (vector<phone>::iterator it=vec_ph.begin();it!=vec_ph.end();++it)
  {
    if (it->result_time.size()==0)
    {
      continue;
    }
    int all_time=0;
    printf("%s %02d\n",it->name,it->result_time[0].month);
    int cnt=0;
    while(cnt<(it->result_time.size()))
    {
        printf("%02d:%02d:%02d %02d:%02d:%02d ",it->result_time[cnt].dd,it->result_time[cnt].hh,it->result_time[cnt].mm,it->result_time[cnt+1].dd,it->result_time[cnt+1].hh,it->result_time[cnt+1].mm);
        int last_time=0;
        int cost=0;
        compute(it->result_time[cnt],it->result_time[cnt+1],rate,last_time,cost,one_cost);
        printf("%d $%d.%02d\n",last_time,cost/100,cost%100);

        all_time+=cost;
        cnt+=2;
    }
    printf("Total amount: $%d.%02d\n",all_time/100,all_time%100);
  }
  return 0;
}