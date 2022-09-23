#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

// maxsubfaster
int maxsubFaster(int arr[], int n) {
  int max, sum;
  int *S;
  S = (int *)malloc(n * sizeof(int));

  // the initial prefix sum
  S[0] = 0;
  for (int i = 1; i < n+1; i++) {
    S[i] = S[i - 1] + arr[i - 1];
  }
  // the max found so far
  for (int j = 0; j < n; j++) {
    for (int k = j ; k < n; k++) {
      sum = S[k+1] - S[j];
      if (sum > max)
        max = sum;
    }
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
  int output = maxsubFaster(A, n);
  clock_t end = clock();

  time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Sum of array: %d\n", temp);
  printf("Max sum (faster): %d\n", output);
  printf("Time taken: %f seconds", time_spent);

  free(A);

  return 0;
}
