#include <iostream>
using namespace std;

void insertion_sort(int array[] , int size)
{
    //Outer loop starts from one as it has to compare ith index with ones below it
    for(int i = 1 ; i < size ; i++)
    {
        //Store ith index
        int key = array[i];

        //J runs backwards comparing indexes below key
        int j = i - 1;

        while(j >= 0 && array[j] < key)
        {
            array[j + 1] = array[j];
            j--;
        }

        //Insert value at its correct index in that loop
        array[j + 1] = key;

    }
}

void display(int array[] , int size)
{
    cout << "Array : ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of books : ";
    cin >> n;
    cout << endl;

    int *arr = new int[n];

    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter serial number " << i << " : ";
        cin >> arr[i];
        cout << endl;
    }

    insertion_sort(arr , n);
    display(arr , n);

    delete[] arr;
}
