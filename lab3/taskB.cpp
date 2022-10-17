#include <iostream>
#include <queue>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    int arr[] = {1,2,3,4,5};
    queue<int> queue;

    printf("Elements in non-reversed order: ");
    for(auto i: arr) // print out the array
    {
        cout<<i<<" ";
        length++;
    }

    // enqueue array into the queue
    for (int i = 0; i < length; i++)
    {
        queue.push(arr[i]);
    }

    printf("\nElements in reversed order: ");
    for (int j = length-1; j >= 0; j--)
    {
        arr[j] = queue.front();
        queue.pop(); // dequeue
        cout << arr[j] << " ";
    }

    return 0;
}
