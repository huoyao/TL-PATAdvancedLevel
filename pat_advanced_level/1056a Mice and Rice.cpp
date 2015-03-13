#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int np, ng,rak[1005],mouse[1005];

int main()
{
  cin >> np >> ng;
  for (int i = 0; i < np; ++i)
    scanf("%d",&mouse[i]);
  vector<int> order;
  for (int i = 0; i < np; ++i)
  {
    int tmp;
    scanf("%d", &tmp);
    order.push_back(tmp);
  }
  int rk = 0,npbak=np;
  while (order.size()>1)
  {
    vector<int> order_;
    for (int i = 0; i < order.size(); i += ng)
    {
      int mxe = order[i];
      for (int j = 0; j < ng && i+j < order.size(); ++j)
      {
        if (mouse[order[i+j]]>mouse[mxe]) mxe = order[i+j];
      }
      order_.push_back(mxe);
    }
    for (int i = 0; i < order.size(); ++i)
      rak[order[i]] = order_.size()+1;
    order = order_;
  }
  rak[order[0]] = 1;
  printf("%d",rak[0]);
  for (int i = 1; i < npbak; ++i)
    printf(" %d",rak[i]);
  printf("\n");
  system("pause");
  return 0;
}