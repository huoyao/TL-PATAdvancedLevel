#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main()
{
  int n,ncircle=0,cnt=0;
  scanf("%d",&n);
  vector<int> arr(n);
  vector<bool> isok(n,false);
  for(int i=0;i<n;++i)
  {
    scanf("%d",&arr[i]);
    if(arr[i]==i) isok[i]=true;
  }
  for(int i=0;i<n;++i)
  {
    if(isok[i]) continue;
    int idx=i;
    int val=arr[idx];
    ++ncircle;
    while(val!=i)
    {
      idx=val;
      val=arr[idx];
      isok[idx]=true;
      ++cnt;
    }
  }
  if(isok[0]) printf("%d\n",cnt+2*ncircle);
  else printf("%d\n",cnt+2*ncircle-2);
  system("pause");
  return 0;
}