#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int n;
double p,r,sum=0.f;

void dfs(int id,double p,vector<vector<int>> &vec)
{
  if(vec[id][0]==-1)
  {
    sum+=(p*(1.+0.01*r)*vec[id][1]);
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
    int ct,tt;
    cin>>ct;
    if(ct==0) 
    {
      cin>>tt;
      vec[i].push_back(-1);
      vec[i].push_back(tt);
    }else
    {
      for(int j=0;j<ct;++j)
      {
        cin>>tt;
        vec[i].push_back(tt);
      }
    }
  }
  for(int i=0;i<vec[0].size() && n>1;++i)
    dfs(vec[0][i],p,vec);
  if(n==1) sum+=p*vec[0][1]; //mark
  printf("%.1lf\n",sum);
  system("pause");
  return 0;
}