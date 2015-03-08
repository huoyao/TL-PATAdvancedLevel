#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int coin[10005],dp[10005][105],isinc[105][10005],n,m;

int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    cin>>coin[i];
  sort(coin+1,coin+n+1,greater<int>());
  for(int i=1;i<=m;++i)
    for(int j=1;j<=n;++j)
      isinc[i][j]=false;
  for(int i=0;i<=m;++i) dp[0][i]=0;
  for(int i=0;i<=n;++i) dp[i][0]=0;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    {
      if(j<coin[i] || dp[i-1][j]>dp[i-1][j-coin[i]]+coin[i])
        dp[i][j]=dp[i-1][j];
      else 
      {
        dp[i][j]=dp[i-1][j-coin[i]]+coin[i];
        isinc[j][i]=true;
      }
    }
  if(dp[n][m]!=m)
  {
    cout<<"No Solution"<<endl;
    return 0;
  }
  bool head=true;
  for(int i=n;i>0 && m>0 ;--i)
  {
    if(isinc[m][i])
    {
      if(!head) {cout<<" "<<coin[i];}
      else {cout<<coin[i]; head=false;}
      m-=coin[i];
    }
  }
  cout<<endl;
  return 0;
}