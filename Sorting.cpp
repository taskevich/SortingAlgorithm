#include <iostream>

using namespace std;

// heapify sort
void heap_sort(int* arr, int size);
void build_heap(int* arr, int size);
void heapify(int* arr, int idx, int max);

// insortion sort
void insortion_sort(int* arr, int size);

// merge sort
void merge_sort(int* copy, int* arr, int start, int end);

int main()
{
    int arr[] = { 1, 5, 9, 4, 0, 4, 2, 54 };
    int size = sizeof(arr) / sizeof(int);


    cout << "\tPopular sorting methods\n"
        << "1. Heapify sort.\n"
        << "2. Insortion sort.\n"
        << "3. Merge sort."
        << endl;


    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            cout << "Heapify sort." << endl;
            cout << "Source array: ";
            for (auto a : arr)
                cout << a << " ";

            heap_sort(arr, size);
            cout << endl << "Sorted array: ";
            for (auto a : arr)
                cout << a << " ";
        }
        break;
        case 2:
        {
            cout << "Insortion sort." << endl;
            cout << "Source array: ";
            for (auto e : arr)
                cout << e << " ";

            
            insortion_sort(arr, size);
            cout << endl << "Sorted array: ";
            for (auto e : arr)
                cout << e << " ";
        }
        break;
        case 3:
        {
            cout << "Merge sort." << endl;
            cout << "Source array: ";
            for (auto e : arr)
                cout << e << " ";

            int* copy = new int[size];
            for (int i = 0; i < size; ++i)
                copy[i] = arr[i];

            merge_sort(copy, arr, 0, size);
            cout << endl << "Sorted array: ";
            for (int i = 0; i < size; ++i)
                cout << copy[i] << " ";
        }
        break;
        default: cout << "Not on the list" << endl;
    }
    return 0;
}

void heap_sort(int* arr, int size)
{
    build_heap(arr, size);
    for (int i = size - 1; i >= 0; --i)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i);
    }

}

void build_heap(int* arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(arr, i, size);
    }
}

void heapify(int* arr, int idx, int max)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < max && arr[left] > arr[idx])
        largest = left;
    else largest = idx;
    if (right < max && arr[right] > arr[largest])
        largest = right;

    if (largest != idx)
    {
        int temp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, max);
    }
}

void insortion_sort(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        int value = arr[i];
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}

void merge_sort(int* copy, int* arr, int start, int end)
{
    if (end - start < 2) return;
    if (end - start == 2)
    {
        if (copy[start] > copy[start + 1])
        {
            int temp = copy[start + 1];
            copy[start + 1] = copy[start];
            copy[start] = temp;
        }
        return;
    }

    int mid = (end + start) / 2;
    merge_sort(arr, copy, start, mid);
    merge_sort(arr, copy, mid, end);

    int i = start;
    int j = mid;
    int idx = start;
    
    while (idx < end)
    {
        if (j >= end || (i < mid && arr[i] < arr[j]))
        {
            copy[idx] = arr[i];
            ++i;
        }
        else
        {
            copy[idx] = arr[j];
            ++j;
        }
        ++idx;
    }

}
