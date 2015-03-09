#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> nam, pas;
  string strnam, strpas;
  bool change = false;
  for (int i = 0; i < n; ++i)
  {
    cin >> strnam >> strpas;
    change = false;
    for (int j = 0; j < strpas.length(); ++j)
    {
      switch (strpas[j])
      {
      case '1':
        strpas[j] = '@';
        change = true;
        break;
      case '0':
        strpas[j] = '%';
        change = true;
        break;
      case 'l':
        strpas[j] = 'L';
        change = true;
        break;
      case 'O':
        strpas[j] = 'o';
        change = true;
        break;
      default:
        break;
      }
    }
    if (change) { nam.push_back(strnam); pas.push_back(strpas); }
  }
  if (nam.size() == 0)
  {
    cout << "There";
    if (n > 1) cout << " are "<<n<<" accounts";
    else cout <<" is "<<n<< " account";
    cout<<" and no account is modified" << endl;
  }
  else
  {
    cout << nam.size() << endl;
    for (int i = 0; i < nam.size(); ++i)
      cout << nam[i] << " " << pas[i]<<endl;
  }
  system("pause");
  return 0;
}