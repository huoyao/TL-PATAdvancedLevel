#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <map>
#include <set>
using namespace std;


int main()
{
  //while(1)
  {
    int n,k;
    scanf("%d %d",&n,&k);
    int max_t=26*26*26*10;
    vector<vector<int>> map_p(max_t+1);
    for (int i=0;i<k;++i)
    {
      int course_id,course_num;
      scanf("%d %d",&course_id,&course_num);
      for (int j=0;j<course_num;++j)
      {
        char name[5];
        scanf("%s",name);
        int tt=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
        map_p[tt].push_back(course_id);
      }
    }
    for (int i=0;i<n;++i)
    {
      char name[5];
      scanf("%s",name);
      printf("%s",name);
      int tt=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
      //if (map_p.find(tt)!=map_p.end())
      vector<int> temp(map_p[tt]);
      sort(temp.begin(),temp.end());
      {
        printf(" %d",temp.size());
        for (vector<int>::iterator it=temp.begin();it!=temp.end();++it)
        {
          printf(" %d",*it);
        }
        printf("\n");
      }//else
      {
       // printf(" 0\n");
      }
    }
  }
  system("pause");
  return 0;
}