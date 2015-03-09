#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string num1="",num2="",num3="";

bool cmp(char a,char b)
{
  return a > b;
}

void convert()
{
  num1 = to_string(n);
  while (num1.length() < 4) num1 += '0';
  sort(num1.begin(), num1.end(),cmp);
  int n1 = stoi(num1);
  num2 = num1;
  sort(num2.begin(),num2.end());
  int n2 = stoi(num2);
  n = n1 - n2;
  num3 = to_string(n);
  while (num3.length() < 4) num3 = '0' + num3;
}

int main()
{
  cin >> n;
  string str = to_string(n);
  bool st = true;
  for (int i = 1; i < str.length(); ++i)
  {
    if (str[i] != str[i - 1]) st = false;
  }
  if (st && str.length()==4) {cout << str << " - " << str <<" = 0000"<< endl; return 0;}
  do
  {
    convert();
    cout << num1 << " - " << num2 << " = " << num3 << endl;  //mark for "num3"
  } while (n != 6174);
  system("pause");
  return 0;
}