#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;
int nc[N], np[N];

int main()
{
  int c, p;
  cin >> c;
  for (int i = 0; i < c; ++i) scanf("%d",&nc[i]);
  cin >> p;
  for (int i = 0; i < p; ++i) scanf("%d",&np[i]);
  sort(nc, nc + c);
  sort(np, np + p);
  int idx = 0,mine=min(c,p);
  long long total = 0;
  while (idx<mine && nc[idx]<0 && np[idx]<0) { total += (long long)nc[idx] * np[idx]; ++idx; }
  int idx1 = c - 1, idx2 = p - 1;
  while (idx1>=0 && idx2>=0 && nc[idx1]>0 && np[idx2]>0) { total += (long long)nc[idx1] * np[idx2]; --idx1; --idx2; }
  cout << total<<endl;
  system("pause");
  return 0;
}