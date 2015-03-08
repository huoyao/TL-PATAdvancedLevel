#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[105],aa[105],b[105];

bool isequal(int *a,int *b)
{
  for(int i=0;i<n;++i)
    if(a[i]!=b[i]) return false;
  return true;
}

void output(int *a)
{
  cout<<a[0];
  for(int i=1;i<n;++i)
    cout<<" "<<a[i];
  cout<<endl;
}

bool ismerge()
{
  bool iseq=false;
  int j;
  for(int i=2;i<=n;i*=2)
  {
    for(j=0;j+i<=n;j+=i)
    {
      sort(aa+j,aa+j+i);
    }
    sort(aa+j,aa+n);
    if(isequal(aa,b)) iseq=true;
    if(iseq && !isequal(aa,b))
    {
      cout<<"Merge Sort"<<endl;
      output(aa);
      return true;
    }
  }
  return false;
}

void isinsert()
{
  bool iseq=false;
  for(int i=2;i<=n;++i)
  {
    sort(a,a+i);
    if(isequal(a,b)) iseq=true;
    if(iseq && !isequal(a,b))
    {
      cout<<"Insertion Sort"<<endl;
      output(a);
      return;
    }
  }
}

int main()
{
  cin>>n;
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    aa[i]=a[i];
  }
  for(int i=0;i<n;++i)
    cin>>b[i];
  if(!ismerge()) isinsert();
  system("pause");
  return 0;
}