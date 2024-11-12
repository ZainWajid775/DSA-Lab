#include <iostream>
using namespace std;

void bubble_sort(int arr[] , int size)
{

    //Outer loops runs n-1 as the comparision is done with i+1 index
    for(int i = 0 ; i < size - 1 ; i++)
    {

        //Inner loops runs until it reaches the index i is at
        //Also -1 to account for last index
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if(arr[j] < arr[j + 1])
            {
                //Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }

}

void display(int arr[] , int size)
{
    cout << "Array : ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[10] = {};

    for (int i = 0 ; i < 10 ; i++)
    {
        cout << "Enter item number " << i << "'s price : ";
        cin >> arr[i];
        cout << endl;
    }

    bubble_sort(arr , 10); 
    
    display(arr , 10);
}