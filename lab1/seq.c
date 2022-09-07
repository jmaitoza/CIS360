#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


// 1st param -> n
// 2nd param -> key (x)

int seq_search(int arr[], int n, int x)
{
   for (int i = 0; i < n; i++)
   {
       if (arr[i] == x)
           return i;
   }
   return -1;
}

int main (int argc, char *argv[])
{
    
    int n,x;

    n = 1000;
    x = rand()%100;
    int keyArray[n];
    double time_spent = 0.0;

    // initalize array with random numbers
    // srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
      keyArray[i] = rand()%1000;
    }
    
    for(int i = 0; i < n; i++)
    {
      printf("\n%d", keyArray[i]);
    }

    // seqential search
    clock_t begin = clock();
  int output = seq_search(keyArray, n, x); 
    clock_t end = clock();  //

    time_spent += (double)(end - begin)/CLOCKS_PER_SEC;

    printf("\nkey: %d\n", x);
    printf("output index: %d", output); 
    
    // calc time difference
    printf("\nTime take to search %d integers: %f seconds", n, time_spent); 
  return 0;
}
