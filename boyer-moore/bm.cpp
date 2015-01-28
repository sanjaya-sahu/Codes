#include <limits.h>
#include <string.h>
#include <stdio.h>

#define NO_OF_CHARS 256

int min (int a, int b) { return (a < b) ? a : b; }

void badCharHeuristic(char *pattern, int size, int badchar[NO_OF_CHARS])
{
  for (int i=0;i < NO_OF_CHARS ;i++)
    badchar[i] = -1;

  for (int i=0; i < size; i++)
    badchar[(int)pattern[i]] = i;
}

void search(char *txt, char *pat)
{
  int m = strlen(pat);
  int n = strlen(txt);

  int badchar[NO_OF_CHARS];

  badCharHeuristic(pat, m, badchar);

  int i = m-1;
  int j = m-1;
  do
  {
    printf("pat[j] = %d, txt[i] = %d\n", pat[j], txt[i]);
    if (pat[j] == txt[i])
    {
      printf("pat[j] = %d\n",pat[j]);
      if (j == 0)
      {
        printf("pattern occurs at %d.\n",i);
        return;
      }
      else {
        i = i - 1;
        j = j - 1;
      }
    }
    else {
      printf("badchar[txt[i]] = %d\n",badchar[txt[i]]);
      i = i + m - min(j, 1 + badchar[txt[i]]);
      j = m - 1;
      printf("new i = %d, new j = %d.\n",i, j);
    }
  } while (i <= n-1);


  return;
}

int main()
{
  char txt[] = "ABCAB";
  char pat[] = "BCA";
  search(txt, pat);

  return 0;
}
