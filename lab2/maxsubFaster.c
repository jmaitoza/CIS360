#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int maxsubFaster(int arr[], int n)
{
  int max, sum;
  int S[n];

  S[0] = 0;
  for (int i = 0; i < n-1; i++)
  {
    S[i] = S[i-1] + arr[i];
  }
  max = 0;
  for(int j = 0; j < n-1; j++)
  {
    for (int k = j; k < n-1; k++)
    {
      sum = S[k] - S[j-1];
      if (sum > max)
        max = sum;
    }
  }
  return max;
}

int main(int argc, char *argv[]) {
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
  int output = maxsubFaster(A, n);
  clock_t end = clock();

  time_spent = (double)(end-begin)/CLOCKS_PER_SEC;

  printf("Max sum (faster): %d\n", output);
  printf("Time taken: %f seconds", time_spent);
 

  return 0;
}
