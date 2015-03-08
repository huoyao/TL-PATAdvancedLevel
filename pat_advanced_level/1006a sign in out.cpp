#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
using namespace std;

bool cmpIn(const int &t1,const int &t2,const int &t3,const int &t4,const int &t5,const int &t6)
{
  if (t1<t4)
  {
    return true;
  }else if (t1==t4)
  {
    if (t2<t5)
    {
      return true;
    }else if (t2==t5)
    {
      if (t3<t6)
      {
        return true;
      }else
      {
        return false;
      }
    }else
    {
      return false;
    }
  }else 
  {
    return false;
  }
}

int main()
{
  int m;
  char name[16],name_in[16],name_out[16];
  scanf("%d",&m);
  int in_h,in_m,in_s,out_h,out_m,out_s;
  scanf("%s %2d:%2d:%2d %2d:%2d:%2d",name,&in_h,&in_m,&in_s,&out_h,&out_m,&out_s);
  strcpy(name_in,name);
  strcpy(name_out,name);
  int t_h,t_m,t_s,o_h,o_m,o_s;
  while(--m)
  {
    scanf("%s %2d:%2d:%2d %2d:%2d:%2d",name,&t_h,&t_m,&t_s,&o_h,&o_m,&o_s);
    if (cmpIn(t_h,t_m,t_s,in_h,in_m,in_s))
    {
      strcpy(name_in,name);
      in_h=t_h;
      in_m=t_m;
      in_s=t_s;
    }
    if (!cmpIn(o_h,o_m,o_s,out_h,out_m,out_s))
    {
      strcpy(name_out,name);
      out_h=o_h;
      out_m=o_m;
      out_s=o_s;
    }
  }
  printf("%s %s\n",name_in,name_out);
  system("pause");
  return 0;
}