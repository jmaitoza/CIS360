#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

#ifndef max
#define max(a,b)        (((a) < (b)) ? (a) :(b))
#endif

int maxsubFastest(int arr[], int n)
{
  int maximum, sum;
  int M[n];

  M[0] = 0;
  for (int t = 0; t < n-1; t++)
  {
    M[t] = max(0, (M[t-1] + arr[t]));
  }
  maximum = 0;
  for (int t = 0; t < n-1; t++)
  {
    maximum = max(0, M[t]);
  }
  return maximum;
}

int main (int argc, char *argv[])
{
  int n, x;
  int A[n];
  double time_spent = 0.0;

  n = 10;
  
  // initialize array with random numbers
  for (int i = 0; i < n; i++)
  {
    A[i] = rand()%10;
  }

  // check to make sure array is seeded properly
  printf("Elements in array A:\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d\n", A[i]);
  }

  // maxsubslow
  clock_t begin = clock();
  int output = maxsubFastest(A, n);
  clock_t end = clock();

  time_spent = (double)(end-begin)/CLOCKS_PER_SEC;

  printf("Max sum (fastest): %d\n", output);
  printf("Time taken: %f seconds", time_spent);
 
 
  return 0;
}
