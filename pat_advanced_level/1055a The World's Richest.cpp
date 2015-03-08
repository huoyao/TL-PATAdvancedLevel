//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <cstdio>
//#include <cmath>
//#include <limits>
//#include <map>
//#include <functional>
//#include <cstring>
//using namespace std;
//
//struct pe
//{
//  char name[10];
//  int age;
//  int bi;
//};
//
//struct sear
//{
//  int cnt;
//  int min_a;
//  int max_a;
//};
//
//bool cmp(const pe &p1,const pe &p2)
//{
//  if (p1.bi==p2.bi)
//  {
//    if (p1.age==p2.age)
//    {
//      if (strcmp(p1.name,p2.name)<0)
//      {
//        return true;
//      }else
//      {
//        return false;
//      }
//    }else{
//      return p1.age<p2.age;
//    }
//  }else
//  {
//    return p1.bi>p2.bi;
//  }
//}
//
//int main()
//{
//  //while(1)
//  {
//    int n,k;
//    scanf("%d %d",&n,&k);
//    vector<vector<pe>> vec_pe(201);
//    for(int i=0;i<n;++i)
//    {
//      pe p;
//      scanf("%s %d %d",p.name,&p.age,&p.bi);
//      vec_pe[p.age].push_back(p);
//    }
//    //sort(vec_pe.begin(),vec_pe.end(),cmp);
//    vector<sear> vec_se;
//    for (int i=0;i<k;++i)
//    {
//      sear se;
//      scanf("%d %d %d",&se.cnt,&se.min_a,&se.max_a);
//      vector<pe> vec_p;
//      for (int ii=se.min_a;ii<=se.max_a;++ii)
//      {
//        for (int iii=0;iii<vec_pe[ii].size();++iii)
//        {
//          vec_p.push_back(vec_pe[ii][iii]);
//        }
//      }
//      sort(vec_p.begin(),vec_p.end(),cmp);
//      printf("Case #%d:\n",i+1);
//      int ii=0;
//      for (;ii<se.cnt && ii<vec_p.size();++ii)
//      {
//        printf("%s %d %d\n",vec_p[ii].name,vec_p[ii].age,vec_p[ii].bi);
//      }
//      if (ii==0)
//      {
//        printf("None\n");
//      }
//    }
//  }
//  system("pause");
//  return 0;
//}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct rich{
  char name[9];
  int age;
  int worth;
  bool operator < (const rich &A) const{
    if (worth != A.worth)
      return worth > A.worth;
    else if (age != A.age)
      return age < A.age;
    else
      return strcmp(name, A.name) < 0;
  }
}num[100000];

int main(){
  //freopen("G:\\input.in", "r", stdin);
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i){
    scanf("%s%d%d", num[i].name, &num[i].age, &num[i].worth);
  }
  sort(num, num + n);
  int ageCount[201] = {0};
  int filter[100001];
  int filter_num = 0;
  for (int i = 0; i < n; i++){
    if (++ageCount[num[i].age] < 101){
      filter[filter_num++] = i;
    }
  }
  for (int i = 1; i <= k; i++){
    int m, amin, amax;
    scanf("%d%d%d", &m, &amin, &amax);
    printf("Case #%d:\n", i);
    int index = 0;
    for (int j= 0; j < filter_num; j++){
      int k = filter[j];
      if (num[k].age >= amin && num[k].age <= amax && index < m){
        printf("%s %d %d\n", num[k].name, num[k].age, num[k].worth);
        index++;
      }
    }
    if (index == 0)
      printf("None\n");
  }
  return 0;
}