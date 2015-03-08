#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <queue>
using namespace std;

struct Node
{
  int num;
  Node *left_child,*right_child;
};

vector<int> vec_post,vec_inorder;
int n;

Node *build_tree(int s1,int e1,int s2,int e2)
{
  Node *new_node=new Node;
  new_node->left_child=NULL;
  new_node->right_child=NULL;
  new_node->num=vec_post[e1];
  int mid_idx;
  for (int i=s2;i<=e2;++i)
  {
    if (vec_inorder[i]==vec_post[e1])
    {
      mid_idx=i;
      break;
    }
  }
  if (mid_idx!=s2)
  {
    new_node->left_child=build_tree(s1,s1+mid_idx-s2-1,s2,mid_idx-1);
  }
  if (mid_idx!=e2)
  {
    new_node->right_child=build_tree(s1+mid_idx-s2,e1-1,mid_idx+1,e2);
  }
  return new_node;
}

void levelOrder(Node *root)
{
  queue<Node *> queue_tree;
  if (root)
  {
    queue_tree.push(root);
  }
  bool first=true;
  while(!queue_tree.empty())
  {
    Node *nod=queue_tree.front();
    queue_tree.pop();
    if (first)
    {
      printf("%d",nod->num);
      first=false;
    }else
    {
      printf(" %d",nod->num);
    }
    if (nod->left_child)
    {
      queue_tree.push(nod->left_child);
    }
    if (nod->right_child)
    {
      queue_tree.push(nod->right_child);
    }
  }
}

int main()
{
  scanf("%d",&n);
  vec_post.resize(n);
  vec_inorder.resize(n);
  for (int i=0;i<n;++i)
  {
    scanf("%d",&vec_post[i]);
  }
  for (int i=0;i<n;++i)
  {
    scanf("%d",&vec_inorder[i]);
  }
  Node *root=build_tree(0,n-1,0,n-1);
  levelOrder(root);
  system("pause");
  return 0;
}