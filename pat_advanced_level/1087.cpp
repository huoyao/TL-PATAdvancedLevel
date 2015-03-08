#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n, k;
  string str_in1,str_in2;
  cin>>n>>k>>str_in1;
  unordered_map<string,int> nodestr;
  unordered_map<int,string> nodenum;
  vector<vector<int> >path(n+1,vector<int>()),cost(n+1,vector<int>(n+1,0));
  vector<int> happ(n+1,0),lcost(n+1,0),lhapp(n+1,0),pathNum(n+1,0);
  vector<double> ahapp(n+1,0);
  vector<bool> istraved(n+1,false);
  nodestr[str_in1] = 1;
  nodenum[1]=str_in1;
  for(int i = 2; i < n+1; ++i){
    cin>>str_in1>>happ[i];
    nodestr[str_in1] = i;
    nodenum[i]=str_in1;
  }
  for(int i = 0; i < k; ++i){
    cin>>str_in1>>str_in2;
    cin>>cost[nodestr[str_in1]][nodestr[str_in2]];
    cost[nodestr[str_in2]][nodestr[str_in1]] = cost[nodestr[str_in1]][nodestr[str_in2]];
  }
  int s = 1;
  int e = nodestr["ROM"];
  istraved[s] = true;
  for(int i = 1; i <= n; ++i){
    lcost[i] = cost[s][i];
    if(cost[s][i]){
      lhapp[i] = happ[i];
      ahapp[i] = happ[i];
      pathNum[i] = 1;
      path[i].push_back(s);
    }
  }
  pathNum[s] = 1;
  while(!istraved[e]){
    int mincost = 0x7fffffff;
    int maxhapp = -1;
    double maxahapp = -1;
    int pos = 0;
    for(int i = 1; i <= n; ++i){
      if(!istraved[i] && lcost[i]){
        if(
          mincost > lcost[i] || 
          (mincost == lcost[i] && maxhapp < lhapp[i]) ||
          (mincost == lcost[i] && maxhapp == lhapp[i] && maxahapp < ahapp[i]) 
          ){
            mincost = lcost[i];
            maxhapp = lhapp[i];
            maxahapp = ahapp[i];
            pos = i;
        }
      }
    }
    istraved[pos] = true;
    for(int i = 1; i <= n; ++i){
      if(!istraved[i] && cost[pos][i]){
        if(lcost[i] == 0 || lcost[i] > lcost[pos] + cost[pos][i]){
          lcost[i] = lcost[pos] + cost[pos][i];
          lhapp[i] = lhapp[pos] + happ[i];
          pathNum[i] = pathNum[pos];
          path[i].clear();
          path[i]=path[pos];
          path[i].push_back(pos);
          ahapp[i] = (lhapp[i] * 1.0) / path[i].size();
        }else if(lcost[i] == lcost[pos] + cost[pos][i]){
          pathNum[i] += pathNum[pos];
          if(
            lhapp[i] < lhapp[pos] + happ[i] ||
            lhapp[i] == lhapp[pos] + happ[i] && ahapp[i] < (lhapp[i]*1.0)/(path[pos].size() + 1)
            ){
              lhapp[i] = lhapp[pos] + happ[i];
              path[i].clear();
              path[i]=path[pos];
              path[i].push_back(pos);
              ahapp[i] = (lhapp[i] * 1.0) / path[i].size();
          }
        }
      }
    }
  }
  cout<<pathNum[e]<<" "<<lcost[e]<<" "<<lhapp[e]<<" ";
  if(path[e].empty()) cout<<"0"<<endl;
  else cout<<lhapp[e]/path[e].size()<<endl;
  for(int i = 0; i < path[e].size(); ++i)
    cout<<nodenum[path[e][i]].c_str()<<"->";
  cout<<"ROM"<<endl;
  return 0;
}