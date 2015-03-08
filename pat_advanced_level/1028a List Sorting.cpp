#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
using namespace std;

struct stu
{
  char id[10];
  char name[10];
  int score;
};

bool cmp1(const stu &t1,const stu &t2)
{
  return strcmp(t1.id,t2.id)<0;
}

bool cmp2(const stu &t1,const stu &t2)
{
  if (strcmp(t1.name,t2.name)==0)
  {
    return strcmp(t1.id,t2.id)<0;
  }else{
    return strcmp(t1.name,t2.name)<0;
  }
}

bool cmp3(const stu &t1,const stu &t2)
{
  if (t1.score==t2.score)
  {
    return strcmp(t1.id,t2.id)<0;
  }else{
    return t1.score<t2.score;
  }
}

int main()
{
  //while(1)
  {
    int n,t;
    scanf("%d %d",&n,&t);
    vector<stu> vec_stu;
    for (int i=0;i<n;++i)
    {
      stu st;
      scanf("%s %s %d",st.id,st.name,&st.score);
      vec_stu.push_back(st);
    }
    switch(t)
    {
    case 1:
      sort(vec_stu.begin(),vec_stu.end(),cmp1);
      break;
    case 2:
      sort(vec_stu.begin(),vec_stu.end(),cmp2);
      break;
    case 3:
      sort(vec_stu.begin(),vec_stu.end(),cmp3);
      break;
    default:
      break;
    }
    for (int i=0;i<n;++i)
    {
      printf("%s %s %d\n",vec_stu[i].id,vec_stu[i].name,vec_stu[i].score);
    }
  }
  system("pause");
  return 0;
}