#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) 
{
    int size_left = mid - left + 1;
    int size_right = right - mid;


    int arr_left[size_left];
    int arr_right[size_right];

    for (int i = 0; i < size_left; i++) 
    {
        arr_left[i] = arr[left + i];
    }
    for (int i = 0; i < size_right; i++) 
    {
        arr_right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < size_left && j < size_right) 
    {
        if (arr_left[i] <= arr_right[j]) 
        {
            arr[k] = arr_left[i];
            i++;
        } 
        else 
        {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }

    while (i < size_left) 
    {
        arr[k] = arr_left[i];
        i++;
        k++;
    }

    while (j < size_right) 
    {
        arr[k] = arr_right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void print(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() 
{
    int n1, n2;

    cout << "Enter number of products in inventory 1 : ";
    cin >> n1;
    cout << endl;

    int temp[n1];
    for (int i = 0; i < n1; i++) 
    {
        cout << "Enter product ID for inventory 1 (product " << i + 1 << ") : ";
        cin >> temp[i];
    }
    cout << endl;


    cout << "Enter number of products in inventory 2 : ";
    cin >> n2;
    cout << endl;

    int size = n1 + n2;
    int arr[size];

    for (int i = 0; i < n1; i++) 
    {
        arr[i] = temp[i];
    }

    for (int i = 0; i < n2; i++) 
    {
        cout << "Enter product ID for inventory 2 (product " << i + 1 << "): ";
        cin >> arr[n1 + i];
    }
    cout << endl;

    merge_sort(arr, 0, size - 1);

    cout << "Sorted inventory: ";
    print(arr, size);

}
