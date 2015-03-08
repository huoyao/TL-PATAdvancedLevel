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

struct st{
  int id,total,mhdst;
};

bool cmp(const st&s1,const st&s2)
{
  if (s1.mhdst!=s2.mhdst)
  {
    return s1.mhdst>s2.mhdst;
  }
  if (s1.total!=s2.total)
  {
    return s1.total<s2.total;
  }
  return s1.id<s2.id;
}

void dij(const int&idx,vector<vector<int>> &vec,const int &siz)
{
  const int MX=0x7fffffff;
  vector<int> dstr(siz,MX);
  vector<int> vist(siz,0);
  dstr[idx]=0;
  for (int i=1;i<siz;++i)
  {
    int maxe=0x7fffffff;
    int min_e;
     for (int j=0;j<siz;++j)
     {
       if (vist[j]==0 && dstr[j]<maxe)
       {
         maxe=dstr[j];
         min_e=j;
       }
     }
     vist[min_e]=1;
     for (int j=0;j<siz;++j)
     {
       if (vist[j]==0 && vec[min_e][j]!=MX)
       {
         if (dstr[j]>dstr[min_e]+vec[min_e][j])
         {
           dstr[j]=dstr[min_e]+vec[min_e][j];
         }
       }
     }
  }
  for (int i=0;i<siz;++i)
  {
    vec[idx][i]=dstr[i];
  }
}

int main()
{
  //while(1)
  {
    int n,m,k,ds;
    scanf("%d %d %d %d",&n,&m,&k,&ds);
    int siz=n+m+1;
    const int MX=0x7fffffff;
    vector<int> tem(siz,MX);
    vector<vector<int>> vec_in(siz,tem);
    for (int i=0;i<k;++i)
    {
      int d1,dst,d2;
      char cc[4],rr[4];
      scanf("%s%s%d",rr,cc,&dst);
      if (rr[0]>='0' && rr[0]<='9')
      {
        d1=0;
        for (int ii=0;ii<strlen(rr);++ii)  // mark for case 4
        {
          d1=(d1*10+rr[ii]-'0');
        }
      }else{
        if (strlen(rr)==3)  //mark 10 case 4
        {
          d1=n+10;
        }else
        {
          d1=n+rr[1]-'0';
        }      
      }
      if (cc[0]>='0' && cc[0]<='9')
      {
        d2=0;
        for (int ii=0;ii<strlen(cc);++ii)
        {
          d2=(d2*10+cc[ii]-'0');
        }
      }else{
        if (strlen(cc)==3)
        {
          d2=n+10;
        }else
        {
          d2=n+cc[1]-'0';
        }  
      }
      vec_in[d1][d2]=dst;
      vec_in[d2][d1]=dst;
    }
    vector<st> vec_st;
    for (int idx=n+1;idx<siz;++idx)
    {
      vector<vector<int>> vec_te=vec_in;
      dij(idx,vec_te,siz);
      st tt;
      tt.id=idx-n;
      bool pt=true;
      tt.total=0;
      tt.mhdst=0x7fffffff;
      for (int i=1;i<=n;++i)
      {
        if (vec_te[idx][i]>ds)
        {
          pt=false;
          break; 
        }
        tt.total+=vec_te[idx][i];
        if (vec_te[idx][i]<tt.mhdst)
        {
          tt.mhdst=vec_te[idx][i];
        }
      }
      if (pt)
      {
        vec_st.push_back(tt);
      }
    }
    if (vec_st.size()==0)
    {
      printf("No Solution\n");
      return 0;
    }
    sort(vec_st.begin(),vec_st.end(),cmp);
    printf("G%d\n%d.0 %.1f\n",vec_st[0].id,vec_st[0].mhdst,vec_st[0].total/(1.f*n));
  }
  system("pause");
  return 0;
}