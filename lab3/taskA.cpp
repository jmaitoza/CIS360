#include <iostream>
#include <stack>
#include <array>
using namespace std;

int main()
{
   int length; 
   int arr[] = {2,4,6,7,69}; 
   //create stack
    stack<int> stack;

   printf("Elements in non-reversed order: ");
   for(auto i: arr) // print out the array
   {
        cout<<i<<" ";
        length++;
   }

   for (int i = 0; i < length; i++) // push the array into the stack
   {
        stack.push(arr[i]);
   }

    printf("\nElements in reversed order: ");
    while (!stack.empty()) // pop the stack and print out the elements
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }

    return 0;
}