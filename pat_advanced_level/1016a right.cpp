#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Record
{
  int mouth;
  int d, h, m;
  bool line;
  int t;
  Record(){}
  Record(int tmouth, int td, int th, int tm, bool tline)
  {
    mouth = tmouth;
    d = td;
    h = th;
    m = tm;
    t = td * 24 * 60 + h * 60 + m;
    line = tline;
  }
  bool operator < (const Record &b) const
  {
    return t < b.t;
  }
};
map<string, vector<Record> > RCD;
int toll[24];

bool cmp(const Record &a, const Record &b)
{
  return a.t < b.t;
}
int get_money(int n)
{
  int h = n / 60;
  int m = n % 60;
  int re = 0, i;
  for (i = 0; i < h; ++i)
    re += toll[i % 24] * 60;
  re += toll[i % 24] * m;
  return re;
}
void print(const string &name, vector<Record> &v)
{
  int n = v.size();
  int tre = 0, ttm = 0, re = 0, tm = 0, k;
  int mouth;
  bool has = false;
  for (int i = 0; i < n - 1; ++i)
  {
    if (v[i].line == 1 && v[i + 1].line == 0)
    {
      if (!has)
      {
        mouth = v[i].mouth;
        printf("%s %02d\n", name.c_str(), mouth);
        has = true;
      }
      printf("%02d:%02d:%02d %02d:%02d:%02d ", v[i].d, v[i].h, v[i].m, v[i + 1].d, v[i + 1].h, v[i + 1].m);
      re = get_money(v[i + 1].t) - get_money(v[i].t);
      tm = v[i + 1].t - v[i].t;
      tre += re;
      ttm += tm;
      printf("%d $%d.%02d\n", tm, re / 100, re % 100);
    }
  }
  if (has)
    printf("Total amount: $%d.%02d\n", tre / 100, tre % 100);
}
int main()
{
  int N, i, tm[4];
  char name[20], state[10];
  for (i = 0; i < 24; ++i)
  {
    scanf("%d", &toll[i]);
  }
  scanf("%d", &N);
  for (i = 0; i < N; ++i)
  {
    scanf("%s %d:%d:%d:%d %s", name, &tm[0], &tm[1], &tm[2], &tm[3], state);
    Record rcd(tm[0], tm[1], tm[2], tm[3], state[1] == 'n');
    RCD[name].push_back(rcd);
  }
  map<string, vector<Record> >::iterator it;
  for (it = RCD.begin(); it != RCD.end(); ++it)
  {
    sort(it->second.begin(), it->second.end(),cmp );
    print(it->first, it->second);
  }
  return 0;
}