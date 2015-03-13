#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
  char nam[12], id[12];
  int gd;
};

int n, gd1, gd2;

bool cmp(const stu &s1,const stu &s2)
{
  return s1.gd > s2.gd;
}

int main()
{
  cin >> n;
  vector<stu> vec;
  for (int i = 0; i < n; ++i)
  {
    stu st;
    scanf("%s%s%d",st.nam,st.id,&st.gd);
    vec.push_back(st);
  }
  cin >> gd1>>gd2;
  int cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    if (vec[i].gd<gd1 || vec[i].gd>gd2) continue;
    else vec[cnt++] = vec[i];
  }
  sort(vec.begin(),vec.begin()+cnt,cmp);
  for (int i = 0; i < cnt; ++i)
    printf("%s %s\n",vec[i].nam,vec[i].id);
  if (cnt == 0) printf("NONE\n");
  system("pause");
  return 0;
}