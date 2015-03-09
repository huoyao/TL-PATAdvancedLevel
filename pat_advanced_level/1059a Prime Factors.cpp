#include <iostream>
#include <cmath>
using namespace std;

const int N = 36000;
bool nprim[N];

void genPrim()
{
  nprim[0] = nprim[1] = true;
  for (int i = 2; i <= N; ++i)
  {
    if (!nprim[i])
    {
      for (int j = i*i; j <= N; j += i) nprim[j] = true;
    }
  }
}

int main()
{
  int num;
  cin >> num;
  cout << num << "=";
  if (num <= 3) { cout << num << endl; return 0; }
  genPrim();
  int sq = (int)sqrt(1.*num);
  bool first = true;
  for (int i = 2; i <= sq; ++i)
  {
    if (num == 1) break;
    if (nprim[i] || num%i != 0) continue;
    int icnt = 0;
    while (num%i == 0)
    {
      num /= i;
      ++icnt;
    }
    if (!first) cout << "*";
    first = false;
    cout << i;
    if (icnt > 1) cout << "^" << icnt;
  }
  system("pause");
  return 0;
}