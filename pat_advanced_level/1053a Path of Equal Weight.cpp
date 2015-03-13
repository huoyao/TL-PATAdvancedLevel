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

const int N = 105;
int n, m, s;
int wt[N];
vector<vector<int> > rec,map(N,vector<int>());

void dfs(int id,int sum,vector<int> &path)
{
  if (sum == s && map[id].size()==0)
  {
    rec.push_back(path);
    return;
  }
  else if (sum > s)
    return;
  for (int i = 0; i < map[id].size(); ++i)
  {
    path.push_back(wt[map[id][i]]);
    dfs(map[id][i], sum + wt[map[id][i]], path);
    path.pop_back();
  }
}

bool cmp(const vector<int> &vec1,const vector<int> &vec2)
{
  int mine = min(vec1.size(),vec2.size());
  for (int i = 0; i < mine; ++i)
  {
    if (vec1[i] < vec2[i]) return false;
    else if (vec1[i]>vec2[i]) return true;
  }
  return vec1.size()>vec2.size();
}

int main()
{
  cin >> n >> m >> s;
  for (int i = 0; i < n; ++i)
    scanf("%d",&wt[i]);
  for (int i = 0; i < m; ++i)
  {
    int cnt,id,tmp;
    cin >> id>>cnt;
    for (int j = 0; j < cnt; ++j)
    {
      scanf("%d",&tmp);
      map[id].push_back(tmp);
    }
  }
  vector<int> tmpp;
  tmpp.push_back(wt[0]);
  dfs(0,wt[0],tmpp);
  sort(rec.begin(),rec.end(),cmp);
  for (int i = 0; i < rec.size(); ++i)
  {
    printf("%d",rec[i][0]);
    for (int j = 1; j < rec[i].size(); ++j)
      printf(" %d",rec[i][j]);
    printf("\n");
  }
  system("pause");
  return 0;
}