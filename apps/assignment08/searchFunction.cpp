//
// File:   searchFunction.cpp
// Author: Alex Willingham
// Purpose:
//
//inspired by https://slaystudy.com/c-program-of-binary-search-using-templates
#include<iostream>
#include <chrono>
using namespace std;

template<typename T>
int binary_search(T arr[],int n,T x)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]<x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// Template function to print array
// n: size of arr
template<typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main()
{
    clock_t start = clock();
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ,12 };
    int n = sizeof(arr) / sizeof(int);
    
    cout << "Array : " << endl;
    PrintArray(arr, n);
    
    int x, index;
    cout<<"Enter value you want to Search: ";
    cin>>x;
    
    index = binary_search(arr, n, x);
    
    if(index==-1)
        cout<<x<<" is not present in the array"<<endl;
    else
        cout<<x<<" is present in the array at position "<<index<<endl;
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
}
