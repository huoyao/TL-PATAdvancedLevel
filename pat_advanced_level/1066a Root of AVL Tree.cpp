#include <iostream>
#include <algorithm>
using namespace std;

struct nod
{
  nod *left, *right;
  int val, ht;
  nod(int v = 0, nod *l = NULL, nod *r = NULL, int h = 0) :val(v), left(l), right(r), ht(h){}
};

int getht(nod *root)
{
  if (root == NULL) return -1;
  else return root->ht;
}

bool isbalance(nod *l,nod *r)
{
  return abs(getht(l)-getht(r))<2;
}

nod *rrot(nod *root)
{
  nod *t = root->left;
  root->left = t->right;
  t->right = root;
  root->ht = max(getht(root->left), getht(root->right)) + 1;
  t->ht = max(getht(t->left),getht(t->right))+1;
  return t;
}

nod *lrot(nod *root)
{
  nod *t = root->right;
  root-> right= t->left;
  t->left = root;
  root->ht = max(getht(root->left), getht(root->right)) + 1;
  return t;
}

nod * insert(nod *root, int val)
{
  if (root == NULL)
  {
    root = new nod(val);
    return root;
  }
  if (val > root->val)
  {
    root->right = insert(root->right, val);
    if (!isbalance(root->left, root->right))
    {
      if (val > root->right->val)
        root=lrot(root);
      else
      {
        root->right=rrot(root->right);
        root=lrot(root);

      }
    }
  }
  else
  {
    root->left = insert(root->left,val);
    if (!isbalance(root->left, root->right))
    {
      if (val < root->left->val)
        root = rrot(root);
      else
      {
        root->left = lrot(root->left);
        root = rrot(root);
      }
    }
  }
  root->ht = max(getht(root->left), getht(root->right)) + 1;
  return root;
}

int main()
{
  int n;
  cin >> n;
  nod *root = NULL;
  for (int i = 0; i < n; ++i)
  {
    int tmp;
    cin >> tmp;
    root = insert(root, tmp);
  }
  cout << root->val << endl;
  system("pause");
  return 0;
}