#include <iostream>
#include <cstdio>
using namespace std;

struct tr
{
  tr *left, *right;
  int val;
  tr(int v) :val(v), left(NULL), right(NULL){}
  tr(){}
};

int n, idx1 = 0, idx2 = 0;

tr *build()
{
  tr *nod = NULL;
  if (idx1 < 2 * n)
  {
    char str[5];
    int t;
    scanf("%s", str);
    if (str[1] == 'u')
    {
      scanf("%d", &t);
      nod = new tr(t);
      ++idx1;
    }
    else
    {
      ++idx1;
      return NULL;
    }
    nod->left = build();
    nod->right = build();
  }
  return nod;
}

void post(tr *root)
{
  if (!root) return;
  post(root->left);
  post(root->right);
  if (idx2 < n-1)
    printf("%d ", root->val);
  else
    printf("%d\n", root->val);
  ++idx2;
}

int main()
{
  cin >> n;
  tr *root;
  root = build();
  post(root);
  system("pause");
  return 0;
}