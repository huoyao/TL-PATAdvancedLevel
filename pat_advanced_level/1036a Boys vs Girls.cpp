#include <iostream>
#include <string>
using namespace std;

struct stu
{
  string nam, id;
  int grade;
};

int main()
{
  int n;
  cin >> n;
  stu stuf, stum;
  stuf.grade = -1;
  stum.grade = 105;
  for (int i = 0; i < n; ++i)
  {
    stu tmp;
    char c;
    cin >> tmp.nam >> c >> tmp.id >> tmp.grade;
    if (c == 'F')
    {
      if (tmp.grade>stuf.grade) stuf = tmp;
    }
    else if (tmp.grade < stum.grade) stum = tmp;
  }
  if (stuf.grade != -1)
    cout << stuf.nam << " " << stuf.id << endl;
  else
    cout << "Absent" << endl;
  if (stum.grade != 105)
    cout << stum.nam << " " << stum.id << endl;
  else
    cout << "Absent" << endl;
  if (stuf.grade != -1 && stum.grade != 105)
    cout << stuf.grade - stum.grade << endl;
  else
    cout << "NA" << endl;
  system("pause");
  return 0;
}