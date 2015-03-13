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
  vector<int> order(55);
  vector<int> order_(55);
  vector<int> ordertmp(55);
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
  {
    scanf("%d", &order[i]);
    ordertmp[i] = i;
  }
  while (rep--)
  {
    for (int i = 1; i <= 54; ++i)
      order_[order[i]] = ordertmp[i];
    ordertmp = order_;
  }
  for (int i = 1; i < 54; ++i)
    printf("%s ", card[ordertmp[i]].c_str());
  printf("%s\n",card[ordertmp[54]].c_str());
  system("pause");
  return 0;
}