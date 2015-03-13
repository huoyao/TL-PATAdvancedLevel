#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
  int rep;
  cin >> rep;
  vector<string> card(55);
  int cnt = 1;
  string cc[4] = {"S","H","C","D"};
  int order[55];
  for (int id = 0; id < 4; ++id)
  {
    for (int i = 1; i < 14; ++i)
    {
      string s=cc[id];
      s += to_string(i);
      card[cnt++] = s;
    }
  }
  card[cnt++] = "J1";
  card[cnt] = "J2";
  for (int i = 1; i < 55; ++i)
    scanf("%d",&order[i]);
  //  order[i] = i + 1;
  //order[54] = 1;
  while (rep--)
  {
    int tp2 = 1,next,cur=order[tp2];
    for (int i = 0; i < 54; ++i)
    {
      next = order[cur];
      order[cur] = tp2;
      tp2 = cur;
      cur=next;
    }
  }
  for (int i = 1; i < 54; ++i)
    printf("%s ", card[order[i]].c_str());
  printf("%s\n",card[order[54]].c_str());
  system("pause");
  return 0;
}