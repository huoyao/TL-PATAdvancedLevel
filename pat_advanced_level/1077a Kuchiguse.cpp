#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  string str,comm;
  cin >> n;
  getchar();
  getline(cin, comm);
  int lenc = comm.length(), lenmin;
  for (int i = 1; i < n; ++i)
  {
    getline(cin,str);
    lenmin = min((int)str.length(),lenc);
    int idx1 = lenc - 1,idx2=str.length()-1;
    while (lenmin)
    {
      if (comm[idx1] != str[idx2]) break;
      --idx1;
      --idx2;
      --lenmin;
    }
    comm = comm.substr(idx1+1, lenc-idx1-1);
    lenc = comm.length();
  }
  if (comm.length() != 0) cout << comm << endl;
  else cout << "nai" << endl;
  system("pause");
  return 0;
}