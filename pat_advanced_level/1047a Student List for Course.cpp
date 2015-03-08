#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <limits>
using namespace std;



int main()
{
  //while(1)
  {
    int n,k;
    scanf("%d %d",&n,&k);
    map<int,vector<string>> vec_stu;
    if (n<=0)
    {
      for (int i=1;i<=k;++i)
      {
        printf("%d 0\n",i);
      }
      return 0;
    }
    for (int i=0;i<n;++i)
    {
      char cc[5];
      int c;
      scanf("%s %d",cc,&c);
      string str(cc);
      int cor;
      for (int j=0;j<c;++j)
      {
        scanf("%d",&cor);
        vec_stu[cor].push_back(str);
      }
    }
    for (int i=1;i<=k;++i)
    {
      printf("%d %d\n",i,vec_stu[i].size());
      if (vec_stu[i].size()==0)
      {
        continue;
      }
      sort(vec_stu[i].begin(),vec_stu[i].end());
      for (int j=0;j<vec_stu[i].size();++j)
      {
        printf("%s\n",vec_stu[i][j].c_str());
      }
    }
  }
  system("pause");
  return 0;
}