#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;


struct node
{
  int level;
  vector<int> child;
};

void fillLevel(vector<node> &vec_node,const int &idx,const int &level)
{
  for (vector<int>::iterator cit=vec_node[idx].child.begin();cit!=vec_node[idx].child.end();++cit)
  {
    vec_node[*cit].level=level+1;
    fillLevel(vec_node,*cit,level+1);
  }
}

bool cmp(const node &n1,const node &n2)
{
  return n1.level<n2.level;
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  vector<node> vec_node(100);
  int k,id,temp_child;
  for (int i=0;i!=m;++i)
  {
    scanf("%d %d",&id,&k);
    for (int j=0;j!=k;++j)
    {
      scanf("%d",&temp_child);
      vec_node[id].child.push_back(temp_child);
    }
  }
  vec_node[1].level=1;
  fillLevel(vec_node,1,1);
  sort(vec_node.begin(),vec_node.end(),cmp);
  vector<int> vec_cnt(n,0);
  int max_level=0;
  for (vector<node>::const_iterator cit=vec_node.cbegin();cit!=vec_node.cend();++cit)
  {
    if (cit->level<=0)
    {
      continue;
    }
    if (cit->level>max_level)
    {
      max_level=cit->level;
    }
    if (cit->child.size()==0)
    {
      ++vec_cnt[cit->level-1];
    }
  }
  printf("%d",vec_cnt[0]);
  for (int i=1;i!=max_level;++i)
  {
    printf(" %d",vec_cnt[i]);
  }
  system("pause");
  return 0;
}