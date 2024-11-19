#include <iostream>
using namespace std;

void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) 
    {
        swap(&arr[low], &arr[mid]);
    }
    if (arr[low] > arr[high]) 
    {
        swap(&arr[low], &arr[high]);
    }
    if (arr[mid] > arr[high]) 
    {
        swap(&arr[mid], &arr[high]);
    }

    swap(&arr[mid], &arr[high]);
    return arr[high];
}

int partition(int arr[] , int low , int high)
{
    int pivot = median(arr, low, high);
    int i = low - 1; 
    for( int j = low ; j < high ; j++)
    {
        if(arr[j] >= pivot)
        {
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return (i + 1);
}

void quickSort(int arr[] , int low , int high)
{
    if(low < high)
    {
        int pi = partition(arr , low , high);
        quickSort(arr , low , pi - 1);
        quickSort(arr , pi + 1 , high);
    }
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int size = 0 ;

    cout << "Enter number of students : ";
    cin >> size;
    cout << endl;
    int arr[size];
    
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Enter student no " << i + 1 << "'s marks : ";
        cin >> arr[i];
    }
    quickSort(arr, 0, size - 1);
    cout << "Sorted array: \n";
    print(arr, size);
}
