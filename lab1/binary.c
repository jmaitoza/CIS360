#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int binary_search(int n, int x, int arr[])
{
  int low, mid, high;

  low = 1; high = n;
  int location = 0;

  while (low <= high && location == 0)
  {
    mid = (low+high)/2;

    if (x == arr[mid])
      location = mid;
    else if(x < arr[mid])
      high = mid -1;
    else
      low = mid+1;
  }
  return location;
}

int main (int argc, char *argv[])
{
  // struct timeval start, end;
  int low, mid, high;
  int n,x;
  double time_spent = 0.0;

  n = 1000000;
  x = rand()%1000;
  int keyArray[n];

  //Populate array SORTED
  for (int i = 0; i < n; i++)
  {
    keyArray[i] = i+1;
  }

  // binary search
  // gettimeofday(&start, NULL);
  clock_t begin = clock();
  int output = binary_search(n, x,keyArray);
  clock_t end = clock();

  time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
  // gettimeofday(&end, NULL);

  printf("\nkey: %d\n", x);
  printf("output index: %d", output);

  // calculate time taken 
  // long seconds = (end.tv_sec - start.tv_sec);
  // float microsec = ((end.tv_sec*1000000 +end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec));
  // printf("\nTime taken to search %d integers: %ld seconds and %lf micro seconds", n, seconds, microsec);
  printf("\nTime take to search %d integers: %f seconds", n, time_spent);
  
  return 0;
}
