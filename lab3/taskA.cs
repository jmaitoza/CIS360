using System;
using System.Collections;

public class TaskA 
{
    public static void Main()
    {
        int arr = new int {3, 6, 9, 12, 69};
        Console.WriteLine(arr);
        // initialize a new stack
        Stack stack = new Stack();

        Console.write("Reverse order: ");
        for (int i = 0; i < arr.length; i++)
        {
            stack.Push(arr[i]);
        }
        for (int j = 0; j < arr.length; j++)
        {
            Console.WriteLine(stack.Pop());
        }
        
    }
}