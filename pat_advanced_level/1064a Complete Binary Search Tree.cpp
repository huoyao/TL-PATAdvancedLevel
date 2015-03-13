#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1005;
int nod[N], tree[N], pos, root;
int n;

void build(int root)
{
  if (root > n) return;
  int l = root << 1, r = (root << 1) + 1;
  build(l);
  tree[root] = nod[pos++];
  build(r);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i)
    scanf("%d", &nod[i]);
  sort(nod,nod+n);
  build(1);
  cout << tree[1];
  for (int i = 2; i <= n; ++i)
    printf(" %d",tree[i]);
  cout << endl;
  system("pause");
  return 0;
}