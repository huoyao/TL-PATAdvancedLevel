#include <iostream>
#include <unordered_map>
using namespace std;

int n,arr[100005];
unordered_map<int,int> map;

int main()
{
  cin>>n;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    ++map[arr[i]];
  }
  for(int i=0;i<n;++i)
    if(map[arr[i]]==1) {cout<<arr[i]<<endl;return 0;}
  cout<<"None"<<endl;
  system("pause");
  return 0;
}