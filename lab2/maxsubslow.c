#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int maxsubSlow(int arr[], int n) 
{
  int max, sum;

  max = 0;
  for (int j = 0; j < n-1; j++)
  {
    for (int k = j; k < n-1; k++)
    {
      sum = 0;
      for (int i = j; i < k; i++)
      {
        sum = sum + arr[i];
      }
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

  n = 100;
  
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
  int output = maxsubSlow(A, n);
  clock_t end = clock();

  time_spent = (double)(end-begin)/CLOCKS_PER_SEC;

  printf("Max sum (slow): %d\n", output);
  printf("Time taken: %f seconds", time_spent);
 

  return 0;
}
