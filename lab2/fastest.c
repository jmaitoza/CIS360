#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

// define MAX function
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// maxsubfastest
int maxsubFastest(int arr[], int n) {
  int max, sum;
  int *M = (int *)malloc(n * sizeof(int));

  // initial prefix sum
  M[0] = 0;
  for (int t = 1; t < n+1; t++) {
    M[t] = MAX(0, M[t - 1] + arr[t-1]); // not sure if arr needs to be t or t-1
  }
  // max found so far
  max = 0;
  for (int t = 0; t < n + 1; t++) {
    max = MAX(max, M[t]);
  }
  return max;
}

int main(int argc, char const *argv[]) {
  int n;
  int *A;
  int temp = 0;
  double time_spent = 0.0;

  n = 5;

  // initialize array with N random numbers
  A = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    A[i] = rand() % 100;
    temp = temp + A[i];
  }

  // print elements in array A
   printf("Elements in array A:\n");
   for (int i = 0; i < n; i++) {
     printf("%d\n", A[i]);
   }

  clock_t start = clock();
  int output = maxsubFastest(A, n);
  clock_t end = clock();

  time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Sum of array: %d\n", temp);
  printf("Max sum (fastest): %d\n", output);
  printf("Time taken: %f seconds", time_spent);

  free(A);

  return 0;
}
