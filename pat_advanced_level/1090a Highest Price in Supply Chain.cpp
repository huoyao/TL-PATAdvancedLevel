#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int n,root,cnt;
double p,r,sum=0.f;

void dfs(int id,double p,vector<vector<int>> &vec)
{
  if(vec[id].size()==0)
  {
    double pp=p*(1.+0.01*r);
    if(abs(pp-sum)<1e-7) ++cnt;
    else if(pp>sum) {sum=pp;cnt=1;}
    return;
  }
  for(int i=0;i<vec[id].size();++i)
    dfs(vec[id][i],p*(1.+0.01*r),vec);
}

int main()
{
  cin>>n>>p>>r;
  vector<vector<int>> vec(n);
  for(int i=0;i<n;++i)
  {
    int ct;
    cin>>ct;
    if(ct==-1) 
      root=i;
    else
      vec[ct].push_back(i);
  }
  for(int i=0;i<vec[root].size() && n>1;++i)
    dfs(vec[root][i],p,vec);
  if(n==1) {sum=p;cnt=1;} //mark
  printf("%.2lf %d\n",sum,cnt);
  system("pause");
  return 0;
}