// Created by harman on 1/11/25.
// Bubble Sort

#include <iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
    for (int i =0;i<n-1;++i)
    {
        for (int j=0;j<n-i-1;++j)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printarray(int arr[],int n)
{
    for (int i =0;i<n;++i)
    {
        cout<<" "<<arr[i];
    }
    cout<<"\n";
}

int main()
{
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    for (int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<"Sorted Array";
    printarray(arr,n);
}