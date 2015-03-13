#include <cstdio>
using namespace std;

int main()
{
  int g1, g2, s1, s2, k1, k2, s, g, k;
  scanf("%d.%d.%d%d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
  int fo = 0;
  k = (k1 + k2) % 29;
  fo = (k1 + k2) / 29;
  s = (s1 + s2 + fo) % 17;
  fo = (s1 + s2 + fo) / 17;
  g = g1 + g2 + fo;
  printf("%d.%d.%d\n",g,s,k);
  return 0;
}