#include <iostream>
#include <vector>
using namespace std;

struct node
{
  node *left, *right;
  int val;
};
int nod[1005], n;
node *root;
vector<int> rec;

bool isbst(int st, int end, int ver, node *&root)
{
  root = new node();
  node *rt = root;
  rt->val = nod[st];
  rt->left = NULL;
  rt->right = NULL;
  int i = st + 1;
  for (; i <= end; ++i)
  {
    if (ver == 0)
    {
      if (nod[i] >= rt->val) break;
    }
    else
      if (nod[i] < rt->val) break;
  }
  for (int j = i + 1; j <= end; ++j)
  {
    if (ver == 0)
    {
      if (nod[j] < rt->val) return false;
    }
    else
      if (nod[j]>=rt->val) return false;
  }
  bool l = true;
  if (i > st+1)
    l = isbst(st+1,i-1,ver,rt->left);
  bool r = true;
  if (i <= end && l)
    r = isbst(i,end,ver,rt->right);
  return l&&r;
}

void postbst(node *root)
{
  if (root != NULL)
  {
    if (root->left)
      postbst(root->left);
    if (root->right)
      postbst(root->right);
    rec.push_back(root->val);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> nod[i];
  if (isbst(0, n - 1, 0, root) || isbst(0, n - 1, 1, root))
  {
    cout << "YES" << endl;
    postbst(root);
    cout << rec[0];
    for (int i = 1; i < n; ++i) cout << " " << rec[i];
    cout << endl;
  }
  else
    cout << "NO" << endl;
  system("pause");
  return 0;
}