#include <iostream>
#include <utility>
#include <random>
using namespace std;

int medianOf3(int arr[3])
{
    int low = arr[0];
    int high = arr[1];
    int mid = arr[2];
    if (low > high)
        swap(low, high);
    if (low > mid)
        swap(low, mid);
    if (mid > high)
        swap(mid, high);
    return mid;
}

int partition(int a[], int low, int high)
{
//    int pivot = a[low]; //set pivot to first element in the array
    // set pivot to median of the 3
    int middle = a[(low+high)/2];
    int temp[3] = {a[low], a[high], middle};
    int pivot = medianOf3(temp);
    int i = low+1;
    int j = high;

    while (i < j)
    {
        while (i < high && a[i] <= pivot)
            i++;
        while (j > low && a[j] >= pivot)
            j--;
        if (i < j)
            std::swap(a[i], a[j]); //used C++ std::swap
    }

    if (i > j) //adjust i to its previous position
        i--; // the end of left subarray
    if (a[low] > a[i])
        std::swap(a[low], a[i]);

    return i;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotpoint = partition(a, low, high);
        quicksort(a, low, pivotpoint - 1);
        quicksort(a, pivotpoint + 1, high);
    }
}

int main()
{
    // create dynamic array
    int a[10];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    // fill array with random numbers
    for (int & i : a)
        i = dis(gen);

    cout << "Unsorted array: ";
    for (int &i : a)
        std::cout << i << " ";

    quicksort(a, 0, 9);
    cout << endl << "Sorted array: ";
    for (int &i : a)
        std::cout << i << " ";

    return 0;
}
