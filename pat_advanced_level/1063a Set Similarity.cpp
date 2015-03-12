#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
  int n, k;
  cin >> n;
  vector<vector<int> > vec(n);
  for (int i = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    for (int j = 0; j < num; ++j)
    {
      int tmp;
      cin >> tmp;
      vec[i].push_back(tmp);
    }
    sort(vec[i].begin(), vec[i].end());
    int end = vec[i].size(),st=0,id=0;
    while (id < end)
    {
      if (vec[i][st] != vec[i][id]) vec[i][++st] = vec[i][id]; 
      ++id;
    }
    vec[i] = vector<int>(vec[i].begin(), vec[i].begin() + st+1);
  }
  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    vector<int> &vec1 = vec[a], &vec2 = vec[b];
    int idx1 = 0, idx2 = 0,nc=0,nt=vec1.size()+vec2.size();
    while (idx1 < vec1.size() && idx2 < vec2.size())
    {
      if (vec1[idx1] == vec2[idx2])
      {
        ++nc; ++idx1; ++idx2;
      }
      else if (vec1[idx1] < vec2[idx2])  ++idx1;
      else ++idx2;
    }
    cout.setf(ios::fixed);
    cout << setprecision(1) << (100 * 1.*nc) / (nt-nc) <<"%"<< endl;
  }
  system("pause");
  return 0;
}