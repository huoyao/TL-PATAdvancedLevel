#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <map>
#include <set>
using namespace std;
struct st
{
  string name;
  int wet;
  set<int> next;
  int num;
};
int max_wet=-1;
int max_idx,total_wet;
int group_num;
vector<st> vec_st;
vector<bool> vec_vist(2005,false); //mark for case 3 --error RE [ 1005 to 2005 ]

void dfs(const int &idx)
{
  vec_vist[idx]=true;
  ++group_num;
  total_wet+=vec_st[idx].wet;
  if (vec_st[idx].wet>max_wet)
  {
    max_wet=vec_st[idx].wet;
    max_idx=idx;
  }
  for (set<int>::iterator it=vec_st[idx].next.begin();it!=vec_st[idx].next.end();++it)
  {
    if (!vec_vist[*it])
    {
      dfs(*it);
    }
  }
}

bool cmp(const st&s1,const st&s2)
{
  return s1.name<s2.name;
}

int main()
{
  //while(1)
  {
    int n,k;
    scanf("%d %d",&n,&k);
    map<string,int> map_idx;    
    int cnt_idx=0;
    for (int i=0;i<n;++i)
    {
      char c1[6],c2[6];
      int val;
      scanf("%s %s %d",c1,c2,&val);
      string str1(c1),str2(c2);
      if (str1==str2)
      {
        continue;
      }
      if (map_idx.find(str1)==map_idx.end())
      {
        map_idx[str1]=cnt_idx++;
        st s1;
        s1.name=str1;
        s1.wet=val;
        vec_st.push_back(s1);
      }else
      {
        vec_st[map_idx[str1]].wet+=val;
      }
      if (map_idx.find(str2)==map_idx.end())
      {
        map_idx[str2]=cnt_idx++;
        st s1;
        s1.name=str2;
        s1.wet=val;
        vec_st.push_back(s1);
      }else
      {
        vec_st[map_idx[str2]].wet+=val;
      }
      vec_st[map_idx[str1]].next.insert(map_idx[str2]);
      vec_st[map_idx[str2]].next.insert(map_idx[str1]);
    }

    vector<st> vec_need;
    for (int i=0;i<vec_st.size();++i)
    {
      if (vec_vist[i])
      {
        continue;
      }
      max_wet=-1;
      max_idx=-1;
      group_num=0;
      total_wet=0;
      dfs(i);
      if (total_wet<=2*k || group_num<=2)
      {
        continue;
      }
      vec_st[max_idx].num=group_num;
      vec_need.push_back(vec_st[max_idx]);
    }
    printf("%d\n",vec_need.size());
    sort(vec_need.begin(),vec_need.end(),cmp);
    for (int i=0;i<vec_need.size();++i)
    {
      printf("%s %d\n",vec_need[i].name.c_str(),vec_need[i].num);
    }
  }
  //system("pause");
  return 0;
}