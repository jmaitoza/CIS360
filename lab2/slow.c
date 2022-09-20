#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

//maxsubSlow
int maxsubSlow(int arr[], int n)
{
    int max, sum;

    //max found so far
    max = 0;
    for (int j = 0; j < n-1;j++)
    {
        for (int k = j; k < n-1; k++)
        {
            //next partial sum we are computing
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

int main(int argc, char const *argv[])
{
    int n; 
    int *A;
    int temp=0;
    double time_spent = 0.0;   

    n = 5;

    //initialize array with N random numbers
    A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand()%100;
        temp = temp + A[i];
    }

    //print elements in array A
    printf("Elements in array A:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    clock_t start = clock();
    int output = maxsubSlow(A, n);
    clock_t end = clock();

    time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Sum of array: %d\n", temp);
    printf("Max sum (slow): %d\n", output);
    printf("Time taken: %f seconds", time_spent);

    free(A);

    return 0;
}
