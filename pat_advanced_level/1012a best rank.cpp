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
#include <map>
using namespace std;

struct stu
{
  char name[7];
  int c_grad,m_grad,e_grad,a_grad;
};

bool cmp_a(const stu &stu_a,const stu &stu_b)
{
  return stu_a.a_grad>stu_b.a_grad;
}

bool cmp_c(const stu &stu_a,const stu &stu_b)
{
  return stu_a.c_grad>stu_b.c_grad;
}

bool cmp_m(const stu &stu_a,const stu &stu_b)
{
  return stu_a.m_grad>stu_b.m_grad;
}

bool cmp_e(const stu &stu_a,const stu &stu_b)
{
  return stu_a.e_grad>stu_b.e_grad;
}

struct info
{
  int grad;
  char c;
};

void search_elem(vector<stu> &stu_a,vector<stu> &stu_c,vector<stu> &stu_m,vector<stu> &stu_e,map<string,info> &map_result)
{
  int rank=1;
  int grade=stu_a.front().a_grad;
  int rank_double=0;
  for (vector<stu>::const_iterator cit=stu_a.cbegin();cit!=stu_a.cend();++cit)
  {
    rank_double=0;
    while(cit!=stu_a.cend() && grade==cit->a_grad)
    {
      string name=cit->name;
      info inf;
      inf.grad=rank;
      inf.c='A';
      map_result[name]=inf;
      ++cit;
      rank_double++;
    }
    rank+=rank_double;
    if (cit!=stu_a.cend())
    {
      grade=cit->a_grad;
    }
    --cit;
  }

  //c
  rank=1;
  grade=stu_c.front().c_grad;
  for (vector<stu>::const_iterator cit=stu_c.cbegin();cit!=stu_c.cend();++cit)
  {
    rank_double=0;
    while(cit!=stu_c.cend() && grade==cit->c_grad)
    {
      string name=cit->name;
      if (map_result[name].grad>rank)
      {
        info inf;
        inf.grad=rank;
        inf.c='C';
        map_result.erase(name);
        map_result[name]=inf;
      }
      rank_double++;
      ++cit;
    }
    rank+=rank_double;
    if (cit!=stu_c.cend())
    {
      grade=cit->c_grad;
    }
    --cit;
  }
  //m
  rank=1;
  grade=stu_m.front().m_grad;
  for (vector<stu>::const_iterator cit=stu_m.cbegin();cit!=stu_m.cend();++cit)
  {
    rank_double=0;
    while(cit!=stu_m.cend() && grade==cit->m_grad)
    {
      string name=cit->name;
      if (map_result[name].grad>rank)
      {
        info inf;
        inf.grad=rank;
        inf.c='M';
        map_result.erase(name);
        map_result[name]=inf;
      }
      rank_double++;
      ++cit;
    }
    rank+=rank_double;
    if (cit!=stu_m.cend())
    {
      grade=cit->m_grad;
    }
    --cit;
  }
  //e
  rank=1;
  grade=stu_e.front().e_grad;
  for (vector<stu>::const_iterator cit=stu_e.cbegin();cit!=stu_e.cend();++cit)
  {
    rank_double=0;
    while(cit!=stu_e.cend() && grade==cit->e_grad)
    {
      string name=cit->name;
      if (map_result[name].grad>rank)
      {
        info inf;
        inf.grad=rank;
        inf.c='E';
        map_result.erase(name);
        map_result[name]=inf;
      }  
      rank_double++;
      ++cit;
    }
    rank+=rank_double;
    if (cit!=stu_e.cend())
    {
      grade=cit->e_grad;
    }
    --cit;
  }
}

int main()
{
  vector<stu> student;
  int n,m;
  scanf("%d %d",&n,&m);
  char in_name[7];
  stu st;
  int cnt=n;
  while(cnt--)
  {
    scanf("%s %d %d %d",st.name,&st.c_grad,&st.m_grad,&st.e_grad);
    st.a_grad=st.c_grad+st.m_grad+st.e_grad;
    student.push_back(st);
  }
  vector<stu> stu_a(student);
  vector<stu> stu_c(student);
  vector<stu> stu_m(student);
  vector<stu> stu_e(student);
  sort(stu_a.begin(),stu_a.end(),cmp_a);
  sort(stu_c.begin(),stu_c.end(),cmp_c);
  sort(stu_m.begin(),stu_m.end(),cmp_m);
  sort(stu_e.begin(),stu_e.end(),cmp_e);
  map<string,info> map_result;
  if (stu_a.size())
  {
    search_elem(stu_a,stu_c,stu_m,stu_e,map_result);
  }
  
  /*int count_num=0;
  int a_rank=1,c_rank=1,m_rank=1,e_rank=1;
  int grad_a,grad_c,grad_m,grad_e;
  if (n>0)
  {
    grad_a=stu_a[0].a_grad;
    grad_c=stu_c[0].c_grad;
    grad_m=stu_m[0].m_grad;
    grad_e=stu_e[0].e_grad;
  }
  for (int i=0;i!=n;++i)
  {
    string name=string(stu_a[i].name);
    if (grad_a!=stu_a[i].a_grad)
    {
      a_rank++;
      grad_a=stu_a[i].a_grad;
    }
    if (map_result.find(name)==map_result.end())
    {
      info inf;
      inf.grad=a_rank;
      inf.c='A';
      map_result[name]=inf;
      ++count_num;
    }
    int t=i+1;
    while(t<n && stu_a[t].a_grad==stu_a[i].a_grad)
    {
      name=stu_a[t].name;
      if (map_result.find(name)==map_result.end())
      {
        info inf;
        inf.grad=a_rank;
        inf.c='A';
        map_result[name]=inf;
        ++count_num;
      }
      ++t;
    }

    name=stu_c[i].name;
    if (grad_c!=stu_c[i].c_grad)
    {
      c_rank++;
      grad_c=stu_c[i].c_grad;
    }
    if (map_result.find(name)==map_result.end())
    {      
      info inf;
      inf.grad=c_rank;
      inf.c='C';
      map_result[name]=inf;
      ++count_num;
    }
    t=i+1;
    while(t<n && stu_c[t].c_grad==stu_c[i].c_grad)
    {
      name=stu_c[t].name;
      if (map_result.find(name)==map_result.end())
      {
        info inf;
        inf.grad=c_rank;
        inf.c='C';
        map_result[name]=inf;
        ++count_num;
      }
      ++t;
    }

    name=stu_m[i].name;
    if (grad_m!=stu_m[i].m_grad)
    {
      m_rank++;
      grad_m=stu_m[i].m_grad;
    }
    if (map_result.find(name)==map_result.end())
    {     
      info inf;
      inf.grad=m_rank;
      inf.c='M';
      map_result[name]=inf;
      ++count_num;
    }
    t=i+1;
    while(t<n && stu_m[t].m_grad==stu_m[i].m_grad)
    {
      name=stu_m[t].name;
      if (map_result.find(name)==map_result.end())
      {
        info inf;
        inf.grad=m_rank;
        inf.c='M';
        map_result[name]=inf;
        ++count_num;
      }
      ++t;
    }

    name=stu_e[i].name;
    if (grad_e!=stu_e[i].e_grad)
    {
      e_rank++;
      grad_e=stu_e[i].e_grad;
    }
    if (map_result.find(name)==map_result.end())
    {    
      info inf;
      inf.grad=e_rank;
      inf.c='E';
      map_result[name]=inf;
      ++count_num;
    }
    t=i+1;
    while(t<n && stu_e[t].e_grad==stu_e[i].e_grad)
    {
      name=stu_e[t].name;
      if (map_result.find(name)==map_result.end())
      {
        info inf;
        inf.grad=e_rank;
        inf.c='E';
        map_result[name]=inf;
        ++count_num;
      }
      ++t;
    }

    if (count_num==n)
    {
      break;
    }
  }*/
  while(m--)
  {
    scanf("%s",in_name);
    string str=string(in_name);
    if (map_result.find(str)==map_result.end())
    {
      printf("N/A\n");
    }else{
      printf("%d %c\n",map_result[str].grad,map_result[str].c);
    }
  }
  system("pause");
  return 0;
}