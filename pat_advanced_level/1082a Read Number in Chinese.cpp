#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string m1[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string m2[] = {"Qian", "Bai", "Shi"};
vector<string> ans;

void convert(int n)
{
  bool start=false;
  char s[5];
  sprintf(s,"%04d",n);
  for(int i=0;i<4;++i)
  {
    if(s[i]=='0')
    {
      if(!start) continue;
      bool allzero=true;
      for(int j=i+1;j<4;++j) if(s[j]!='0') allzero=false;
      if(allzero) return;
      if(s[i-1]!='0') ans.push_back("ling");
    }else
    {
      start=true;
      ans.push_back(m1[s[i]-'0']);
      if(i<3) ans.push_back(m2[i]);
    }
  }
}

int main()
{
  int n,ncircle=0,cnt=0;
  scanf("%d",&n);
  if(n<0) {ans.push_back("Fu"); n=-n;}
  int n3=n/100000000,n2=n%100000000/10000,n1=n%10000;
  if(n3)
  {
    convert(n3);
    ans.push_back("Yi");
  }
  if(n2)
  {
    if(n2<1000 && n3) ans.push_back("ling");
    convert(n2);
    ans.push_back("Wan");
  }
  if(n1)
  {
    if(n1<1000 && (n2 || n3)) ans.push_back("ling");
    convert(n1);
  }
  if(ans.empty()) {printf("ling\n"); return 0;}
  printf("%s",ans[0].c_str());
  for(int i=1;i<ans.size();++i)
    printf(" %s",ans[i].c_str());
  system("pause");
  return 0;
}