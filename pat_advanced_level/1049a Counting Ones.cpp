#include <iostream>
using namespace std;


int main()
{
  int n,cnt=0,x=1;
  cin >> n;
  while (n/x!=0)
  {
    int left = n / (x*10);
    int right = n%x;
    int cur = n / x % 10;
    if (cur == 0)
      cnt += left*x;
    else if (cur == 1)
      cnt += left*x + right + 1;
    else
      cnt += (left + 1)*x;
    x *= 10;
  }
  cout << cnt << endl;
  system("pause");
  return 0;
}