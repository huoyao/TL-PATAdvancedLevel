#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct moon
{
  double num,price;
};

bool cmp(const moon &a,const moon &b)
{
  return a.price/a.num > b.price/b.num;
}

int main()
{
  int n, d;
  cin >> n >> d;
  vector<moon> vec(n);
  for (int i = 0; i < n; ++i)
    cin >> vec[i].num;
  for (int i = 0; i < n; ++i)
  {
    cin >> vec[i].price;
  }
  sort(vec.begin(),vec.end(),cmp);
  double total=0.;
  for (int i = 0; i < n; ++i)
  {
    if (d == 0) break;
    if (d >= vec[i].num) { total += vec[i].price; d -= vec[i].num; }
    else { total += (d*vec[i].price/vec[i].num); d = 0; }
  }
  cout.setf(ios::fixed);
  cout << setprecision(2) << total<< endl;
  system("pause");
  return 0;
}