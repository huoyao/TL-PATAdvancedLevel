#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  char sig1, sig2, integ, frac[10005];
  int expo;
  scanf("%c%c.%[^E]%*c%c%d", &sig1, &integ, frac, &sig2, &expo);
  if (sig1 == '-') printf("-");
  if (sig2 == '+')
  {
    printf("%c", integ);
    int i = 0;
    bool more=true;
    for (; i < expo && frac[i]; ++i)
      printf("%c", frac[i]);
    while (i < expo) { printf("0"); ++i; more = false; }
    if (more)
    {
      if (frac[i])printf(".");
      while (frac[i]) printf("%c", frac[i++]);
    }
  }
  else
  {
    if (expo == 0) printf("%c.%s", integ, frac);
    else
    {
      printf("0.");
      for (int i = 0; i < expo - 1; ++i)
        printf("0");
      printf("%c%s",integ,frac);
    }
  }
  printf("\n");
  system("pause");
  return 0;
}