#include <iostream>
#include <algorithm>
using namespace std;

int n,dis[100005],m,alldst=0;

int main()
{
  cin>>n;
  dis[1]=0;
  for(int i=1;i<=n;++i)
  {
    int tmp;
    cin>>tmp;
    dis[i+1]=dis[i]+tmp;
    alldst+=tmp;
  }
  cin>>m;
  for(int i=0;i<m;++i)
  {
    int a,b,tmpsum;
    cin>>a>>b;
    if(a>b) swap(a,b);
    tmpsum=dis[b]-dis[a];
    cout<<min(alldst-tmpsum,tmpsum)<<endl;
  }
  return 0;
}