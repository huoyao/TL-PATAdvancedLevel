#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

char str1[85], str2[85];

int main()
{
  scanf("%s%s",str1,str2);
  for (int i = 0; str1[i]; ++i) str1[i] = toupper(str1[i]);
  for (int i = 0; str2[i]; ++i) str2[i] = toupper(str2[i]);
  vector<bool> vst(256,false);
  for (int i = 0,j=0; str1[i]; ++i)
  {
    if (str1[i] != str2[j])
    {
      if (!vst[str1[i]])
      {
        vst[str1[i]] = true;
        cout << str1[i];
      }
    }
    else ++j;
  }
  printf("\n");
  system("pause");
  return 0;
}