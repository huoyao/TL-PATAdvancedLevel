#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;


int main()
{
  string str;
  getline(cin,str);
  char c;
  vector<bool> asc(256, false);
  while (c = getchar())
  {
    if (c == '\n') break;
    asc[c] = true;
  }
  for (int i = 0; i < str.length(); ++i)
  {
    if (!asc[str[i]]) printf("%c",str[i]);
  }
  cout << endl;
  system("pause");
  return 0;
}