#include <iostream>
using namespace std;

void selection_sort(int * arr , int size)
{
    //Compare each index to the first one an change everytime a smaller one is found
    //Every run sets the lowest number to the left
    for(int i = 0 ; i < size - 1 ; i++)
    {
        int min_index = i;

        for(int j = i + 1 ; j < size ; j++)
        {
            if(arr[j] > arr[min_index])
            {
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void print(int * arr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;

    cout << "Enter number of orders : ";
    cin >> n;
    cout << endl;

    int arr[n];

    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter ID of order number  " << i << " : ";
        cin >> arr[i];
        cout << endl;
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr , size);
    print(arr , size);
}