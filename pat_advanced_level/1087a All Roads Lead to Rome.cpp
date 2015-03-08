#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
  int n,m,hpp,num,cst;
  string add1,add2,add3;
  cin>>n>>m>>add1;
  unordered_map<string,int> mapstr;
  unordered_map<int,string> mapnum;
  vector<vector<int> > cost(n+1,vector<int>(n+1,0)),path(n+1,vector<int>());
  vector<int> lcost(n+1,0),lhap(n+1,0),hap(n+1,0),pathnum(n+1,0);
  vector<double> ahap(n+1,0);
  vector<bool> vst(n+1,false);
  mapstr[add1]=1;
  mapnum[1]=add1;
  for(int i=2;i<=n;++i)
  {
    cin>>add2>>hpp;
    hap[i]=hpp;
    mapstr[add2]=i;
    mapnum[i]=add2;
  }
  for(int i=0;i<m;++i)
  {
    cin>>add2>>add3>>cst;
    cost[mapstr[add2]][mapstr[add3]]=cst;
    cost[mapstr[add3]][mapstr[add2]]=cst;
  }
  int s=1,e=mapstr["ROM"];
  for(int i=1;i<=n;++i)
  {
    lcost[i]=cost[s][i];
    if(cost[s][i])
    {
      lhap[i]=hap[i];
      ahap[i]=hap[i];
      pathnum[i]=1;
      path[i].push_back(s);
    }
  }
  pathnum[s]=1;
  vst[s]=true;
  while(!vst[e])
  {
    int mincost=0x7fffffff,maxhap=-1,pos=0;
    double maxahap=-1;
    for(int i=1;i<=n;++i)
    {
      if(!vst[i] && lcost[i])
      {
        if(lcost[i]<mincost || (lcost[i]==mincost && lhap[i]>maxhap) 
          || (lcost[i]==mincost && lhap[i]==maxhap && ahap[i]>maxahap))
        {
          mincost=lcost[i];
          maxhap=lhap[i];
          maxahap=ahap[i];
          pos=i;
        }
      }
    }
    vst[pos]=true;
    for(int i=1;i<=n;++i)
    {
       if(!vst[i] && cost[pos][i])
       {
          if(lcost[i]==0 || lcost[i]>lcost[pos]+cost[pos][i])
          {
            lcost[i]=lcost[pos]+cost[pos][i];
            lhap[i]=lhap[pos]+hap[i];
            pathnum[i]=pathnum[pos];
            path[i].clear();
            path[i]=path[pos];
            path[i].push_back(pos);
            ahap[i]=(lhap[i]*1.f)/path[i].size();
          }else if(lcost[i]=lcost[pos]+cost[pos][i])
          {
            pathnum[i]+=pathnum[pos];
            if(lhap[pos]+hap[i]>lhap[i] || (lhap[pos]+hap[i]==lhap[i] && ahap[i]<(lhap[i]*1.f)/(path[pos].size()+1)))
            {
              lhap[i]=lhap[pos]+hap[i];
              path[i].clear();
              path[i]=path[pos];
              path[i].push_back(pos);
              ahap[i]=(lhap[i]*1.f)/path[i].size();
            }
          }
       }
    }
  }
  cout<<pathnum[e]<<" "<<lcost[e]<<" "<<lhap[e];
  if(path[e].empty()) cout<<" 0"<<endl;
  else cout<<" "<<lhap[e]/path[e].size()<<endl;
  for(int i=0;i<path[e].size();++i)
  {
    cout<<mapnum[path[e][i]]<<"->";
  }
  cout<<"ROM"<<endl;
  return 0;
}

