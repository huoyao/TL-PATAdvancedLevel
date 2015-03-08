#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
using namespace std;

struct station
{
  double price;
  int dist;
};

bool cmp(const station &st1,const station &st2)
{
  return st1.dist<st2.dist;
}

int main()
{
  //while(1)
  {
    double tank;
     int dst,avg_dst,gas;
    scanf("%lf %d %d %d",&tank,&dst,&avg_dst,&gas);
    station st;
    vector<station> vec_st;
    for (int i=0;i<gas;++i)
    {
      scanf("%lf %d",&st.price,&st.dist);
      vec_st.push_back(st);
    }
    sort(vec_st.begin(),vec_st.end(),cmp);
    double price_=0,tank_=0;
    int dst_=0;
    for (int i=0;i<gas;)
    {
      int j;
      double tt=tank_;
      tank_-=(vec_st[i].dist-dst_)/(1.f*avg_dst);
      //dst_=vec_st[i].dist;
      if (tank_<0)
      {
        printf("The maximum travel distance = %.2lf\n",dst_+tt*avg_dst);
        return 0;
      }
      for (j=i+1;j<gas;++j)
      {
        if (vec_st[j].price<vec_st[i].price)
        {
          break;
        }
      }
      int target_d;
      if (j<gas)
      {
        target_d=vec_st[j].dist;
      }else
      {
        target_d=dst;
      }
      dst_=vec_st[i].dist;
      //printf("*****%lf\n",(target_d-dst_)/(1.f*avg_dst)+tank_);
      if ((target_d-dst_)/(1.f*avg_dst)<=tank_)
      {
        //tank_+=(target_d-dst_)/(1.f*avg_dst);
        //price_+=(target_d-dst_)/(1.f*avg_dst)*vec_st[i].price;
        i=j;
      }else if ((target_d-dst_)/(1.f*avg_dst)<=tank)
      {
        double ttank=(target_d-dst_)/(1.f*avg_dst)-tank_;
        tank_+=ttank;
        price_+=ttank*vec_st[i].price;
        i=j;
      }else
      {
        price_+=(tank-tank_)*vec_st[i].price;
        tank_=tank;
        ++i;
      }
    }
    double tt=tank_;
    tank_-=(dst-dst_)/(1.f*avg_dst);
    //dst_=vec_st[i].dist;
    if (tank_<0)
    {
      printf("The maximum travel distance = %.2lf\n",dst_+tt*avg_dst);
      return 0;
    }else
    {
      printf("%.2lf\n",price_);
    }
  }
  system("pause");
  return 0;
}