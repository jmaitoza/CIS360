#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    int temp = 0;
    int length = 0;

    printf("Elements in non-reversed order: ");
    for(auto i: arr) // print out the array
    {
        cout<<i<<" ";
        length++;
    }

    //reverse array using temp variable
    printf("\nElements in reversed order: ");
    for (int i = 0; i < length/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length-i-1];
        arr[length-i-1] = temp;
    }


    for(auto j: arr)
    {
        cout<<j<<" ";
    }

    return 0;
}
