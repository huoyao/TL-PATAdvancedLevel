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

struct sc
{
  int id,total,maxidx;
  vector<int> vec_sc;
};

bool cmp(const sc &s1,const sc&s2)
{
  if (s1.total!=s2.total)
  {
    return s1.total>s2.total;
  }
  if (s1.maxidx!=s2.maxidx)
  {
    return s1.maxidx>s2.maxidx;
  }
  return s1.id<s2.id;
}

int main()
{
  //while(1)
  {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> m_rank(m+1);
    for (int i=1;i<=m;++i)
    {
      scanf("%d",&m_rank[i]);
    }
    sc ss;
    vector<int> temp(m+1,-2);
    ss.vec_sc=temp;
    ss.total=0;
    vector<sc> vec_all(10005,ss);
    set<int> need;
    for (int i=0;i<k;++i)
    {
      int id,rk,cs;
      scanf("%d %d %d",&id,&rk,&cs);
      if (vec_all[id].vec_sc[rk]<cs)
      {
        vec_all[id].vec_sc[rk]=cs;
      }
      if (cs!=-1)
      {
        need.insert(id);
      }
    }
    vector<sc> vec_need;
    for (set<int>::const_iterator cit=need.cbegin();cit!=need.cend();++cit)
    {
      vec_need.push_back(vec_all[*cit]);
      int max_t=-1,cidx=0;
      sc &cd=vec_need.back();
      cd.id=*cit;
      for (int i=1;i<=m;++i)
      {
        if (cd.vec_sc[i]>=0)
        {
          cd.total+=cd.vec_sc[i];
          if (cd.vec_sc[i]>max_t)
          {
            max_t=cd.vec_sc[i];
          }
        }
        if (cd.vec_sc[i]==m_rank[i])  //mark for case 4
        {
          ++cidx;
        }
      }
      cd.maxidx=cidx;
    }
    sort(vec_need.begin(),vec_need.end(),cmp);
    int cnt=1;
    int cc=vec_need[0].total;
    for (int i=0;i<vec_need.size();++i)
    {
      if (vec_need[i].total!=cc)
      {
        cnt=i+1;
        cc=vec_need[i].total;
      }
      printf("%d %05d %d",cnt,vec_need[i].id,vec_need[i].total);
      for(int idx=1;idx<=m;++idx)
      {
        if (vec_need[i].vec_sc[idx]>=0)
        {
          printf(" %d",vec_need[i].vec_sc[idx]);
        }else if (vec_need[i].vec_sc[idx]==-1)
        {
          printf(" 0");
        }else
        {

          printf(" -");
        }
      }
      printf("\n");
    }
  }
  system("pause");
  return 0;
}