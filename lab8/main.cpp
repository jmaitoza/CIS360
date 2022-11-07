#include <iostream>
#include <utility>
#include <random>
#include <iomanip>
#include <chrono>
#define SIZE 100

using namespace std;

//inline
//std::chrono::time_point<std::chrono::high_resolution_clock>
//now()
//{
//    return std::chrono::high_resolution_clock::now();
//}
//template <typename T>
//inline
//std::chrono::milliseconds::rep
//milliseconds(const T& t)
//{
//    return std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
//}

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

void insertionSort(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = a[i];
        int j = i-1;

        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void quicksort(int a[], int low, int high, int size)
{
    if (low < high)
    {
        int pivotpoint = partition(a, low, high);
        if (size <= 10)
        {
            cout << endl << "Insertion sort called" << endl;
            insertionSort(a, size);
        }
        else
        {

            quicksort(a, low, pivotpoint - 1,size);
            quicksort(a, pivotpoint + 1, high,size);
        }
    }
}

int main()
{
    // create dynamic array
    // int size = 10;
    int a[SIZE];
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(1, 100);
    // fill array with random numbers
    for (int & i : a)
        i = dis(mt);

//    cout << "Unsorted array: ";
//    for (int &i : a)
//        std::cout << i << " ";

    // start clock cycle time
    auto start = chrono::steady_clock::now();
    quicksort(a, 0, SIZE-1, SIZE);
    // stop timer
    auto stop = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if (SIZE > 10)
        cout << endl << "Quicksort called" << endl;
//    cout << "Sorted array: ";
//    for (int &i : a)
//        std::cout << i << " ";

    // print time spent
    cout << endl << "Time spent: " << duration.count() << " microseconds" << endl;
    return 0;
}
