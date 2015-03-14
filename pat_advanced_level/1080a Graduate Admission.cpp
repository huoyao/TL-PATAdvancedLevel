#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stu
{
  int ge, gi,id,fina;
  int apl[6];
};

struct sch
{
  int quota,lastrk; //mark for lastrk
  vector<int> stid;
};

int n, m, k;
stu st[40005];
sch sh[105];

bool cmp(const stu &s1,const stu &s2)
{
  if (s1.fina != s2.fina)
    return s1.fina> s2.fina;
  else return s1.ge > s2.ge;
}

int main()
{
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i)
  {
    scanf("%d", &sh[i].quota);
  }
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d",&st[i].ge,&st[i].gi);
    st[i].fina = (st[i].ge + st[i].gi);
    for (int j = 0; j < k; ++j)
    {
      scanf("%d",&st[i].apl[j]);
    }
    st[i].id = i;
  }
  sort(st,st+n,cmp);
  for (int i = 0; i < n; ++i)
  {
    stu &curst = st[i];
    for (int j = 0; j < k; ++j)
    {
      int &schid = curst.apl[j];
      sch &cursch = sh[schid];
      if (cursch.quota>0 
        || (curst.ge == st[cursch.lastrk].ge && curst.fina == st[cursch.lastrk].fina))
      {
        cursch.stid.push_back(curst.id);
        cursch.lastrk = i;
        --cursch.quota;
        break;
      }
    }
  }
  for (int i = 0; i < m; ++i)
  {
    vector<int> &vecid = sh[i].stid;
    sort(vecid.begin(), vecid.end());
    if (vecid.size()) printf("%d",vecid[0]);
    for (int j = 1; j < vecid.size(); ++j)
      printf(" %d",vecid[j]);
    printf("\n");
  }
  system("pause");
  return 0;
}