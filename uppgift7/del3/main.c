#include <stdio.h>
#define XVALUE 10000
#define YVALUE XVALUE

unsigned char array[XVALUE][YVALUE];

int update_array1 (void)
{
  int i, j;
  for (i = 0; i < XVALUE; i++)
      for (j = 0; j < YVALUE; j++) {
         array[j][i]++;

      }

  return 0;
}

int update_array2 (void)
{
   int i, j;
   for (i = 0; i < XVALUE; i++)
      for (j = 0; j < YVALUE; j++)
      {
        array[i][j]++;
      }
  return 0;
}

int main()
{
  int retval;
  retval = update_array1();
  retval = update_array2();

  return retval;

}
