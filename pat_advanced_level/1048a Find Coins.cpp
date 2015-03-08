#include <iostream>
#include <algorithm>
using namespace std;

int n,m,coin[100005];

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;++i)
    cin>>coin[i];
  sort(coin,coin+n);
  int a=0,b=n-1;
  while(a<b)
  {
    int tmpsum=coin[a]+coin[b];
    if(tmpsum==m) break;
    else if(tmpsum>m) --b;
    else ++a;
  }
  if(a>=b) cout<<"No Solution"<<endl;
  else cout<<coin[a]<<" "<<coin[b]<<endl;
  return 0;
}