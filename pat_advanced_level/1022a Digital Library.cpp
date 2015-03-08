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
#include <sstream>
using namespace std;


int main()
{
  map<string,vector<string>> titile;
  map<string,vector<string>> author;
  map<string,vector<string>> keyword;
  map<string,vector<string>> publish;
  map<string,vector<string>> year;
  int n;
  scanf("%d\n",&n);
  while(n--)
  {
    char ch[85];
    string strid;
    getline(cin,strid);
    string str;
    getline(cin,str);
    titile[str].push_back(strid);
    getline(cin,str);
    author[str].push_back(strid);
    getline(cin,str);
    stringstream sstr(str);
    string str_key;
    while(sstr>>str_key)
    {
      keyword[str_key].push_back(strid);
    }
    getline(cin,str);
    publish[str].push_back(strid);
    getline(cin,str);
    year[str].push_back(strid);
  }
  for (map<string,vector<string>>::iterator it=titile.begin();it!=titile.end();++it)
  {
    sort(it->second.begin(),it->second.end());
  }
  for (map<string,vector<string>>::iterator it=author.begin();it!=author.end();++it)
  {
    sort(it->second.begin(),it->second.end());
  }
  for (map<string,vector<string>>::iterator it=keyword.begin();it!=keyword.end();++it)
  {
    sort(it->second.begin(),it->second.end());
  }
  for (map<string,vector<string>>::iterator it=publish.begin();it!=publish.end();++it)
  {
    sort(it->second.begin(),it->second.end());
  }
  for (map<string,vector<string>>::iterator it=year.begin();it!=year.end();++it)
  {
    sort(it->second.begin(),it->second.end());
  }
  int m;
  scanf("%d",&m);
  while(m--)
  {
    int idx;
    char ch[85];
    scanf("%d: ",&idx);
    string str;
    getline(cin,str);
    //scanf("%*c");
    printf("%d: %s\n",idx,str.c_str());
    switch(idx)
    {
    case 1:
      if (titile.find(str)==titile.end())
      {
        printf("Not Found\n");
        break;
      }else
      {
        for (int i=0;i<titile[str].size();++i)
        {
          printf("%s\n",titile[str][i].c_str());
        }
        break;
      }
    case 2:
      if (author.find(str)==author.end())
      {
        printf("Not Found\n");
        break;
      }else
      {
        for (int i=0;i<author[str].size();++i)
        {
          printf("%s\n",author[str][i].c_str());
        }
        break;
      }
    case 3:
      if (keyword.find(str)==keyword.end())
      {
        printf("Not Found\n");
        break;
      }else
      {
        for (int i=0;i<keyword[str].size();++i)
        {
          printf("%s\n",keyword[str][i].c_str());
        }
        break;
      }
    case 4:
      if (publish.find(str)==publish.end())
      {
        printf("Not Found\n");
        break;
      }else
      {
        for (int i=0;i<publish[str].size();++i)
        {
          printf("%s\n",publish[str][i].c_str());
        }
        break;
      }
    case 5:
      if (year.find(str)==year.end())
      {
        printf("Not Found\n");
        break;
      }else
      {
        for (int i=0;i<year[str].size();++i)
        {
          printf("%s\n",year[str][i].c_str());
        }
        break;
      }
    default:
      break;
    }
  }
  system("pause");
  return 0;
}