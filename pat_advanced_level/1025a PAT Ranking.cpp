#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
using namespace std;

struct pat
{
  char name[15];
  int score;
  int final_rank;
  int local_rank;
  int location;
};

bool cmp_local(const pat &pa,const pat &pb)
{
  if (pa.score==pb.score)
  {
    if (strcmp(pa.name,pb.name)<0)
    {
      return true;
    }else
    {
      return false;
    }
  }else
  {
    return pa.score>pb.score;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<pat> vec_pat;
  int idx=0;
  for (int i=1;i<=n;++i)
  {
    int k;
    scanf("%d",&k);
    for (int j=0;j<k;++j)
    {
      pat p;
      scanf("%s %d",p.name,&p.score);
      p.location=i;
      vec_pat.push_back(p);
    }
    sort(vec_pat.begin()+idx,vec_pat.end(),cmp_local);
    int rank=1,r=1;
    int sc=vec_pat[idx].score;
    for (int j=idx;j<vec_pat.size();++j)
    {
      if (vec_pat[j].score!=sc)
      {
        sc=vec_pat[j].score;
        rank=r;
      }
      vec_pat[j].local_rank=rank;
      ++r;
    }
    idx+=k;
  }
  sort(vec_pat.begin(),vec_pat.end(),cmp_local);
  int rank=1,r=1;
  int sc=vec_pat[0].score;
  for (int j=0;j<vec_pat.size();++j)
  {
    if (vec_pat[j].score!=sc)
    {
      sc=vec_pat[j].score;
      rank=r;
    }
    vec_pat[j].final_rank=rank;
    ++r;
  }
  printf("%d\n",vec_pat.size());
  for (int i=0;i<vec_pat.size();++i)
  {
    printf("%s %d %d %d\n",vec_pat[i].name,vec_pat[i].final_rank,vec_pat[i].location,vec_pat[i].local_rank);
  }
  system("pause");
  return 0;
}