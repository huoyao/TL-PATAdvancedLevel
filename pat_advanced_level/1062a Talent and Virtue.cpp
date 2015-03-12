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

struct stu
{
  int id, v, t;
};

bool cmp(const stu &st1, const stu &st2)
{
  int a = st1.v + st1.t, b = st2.v + st2.t;
  if (a > b) return true;
  else if (a < b) return false;
  if (st1.v>st2.v) return true;
  else if (st1.v < st2.v) return false;
  return st1.id < st2.id;
}

int main()
{
  int m, l, h, n = 0;
  cin >> m >> l >> h;
  vector<stu> sage, noble, fool, small;
  for (int i = 0; i < m; ++i)
  {
    stu st;
    scanf("%d%d%d",&st.id,&st.v,&st.t);
    if (st.v < l || st.t < l) continue;
    if (st.v >= h && st.t >= h) sage.push_back(st);
    else if (st.v >= h && st.t < h) noble.push_back(st);
    else if (st.v < h && st.t < h && st.v >= st.t) fool.push_back(st);
    else small.push_back(st);
    ++n;
  }
  cout << n << endl;
  sort(sage.begin(), sage.end(), cmp);
  for (int j = 0; j < sage.size(); ++j)
    printf("%d %d %d\n", sage[j].id ,sage[j].v ,sage[j].t);
  sort(noble.begin(), noble.end(), cmp);
  for (int j = 0; j < noble.size(); ++j)
    printf("%d %d %d\n", noble[j].id ,noble[j].v,noble[j].t);
  sort(fool.begin(), fool.end(), cmp);
  for (int j = 0; j < fool.size(); ++j)
    printf("%d %d %d\n", fool[j].id ,fool[j].v ,fool[j].t);
  sort(small.begin(), small.end(), cmp);
  for (int j = 0; j < small.size(); ++j)
    printf("%d %d %d\n", small[j].id ,small[j].v , small[j].t);
  return 0;
}