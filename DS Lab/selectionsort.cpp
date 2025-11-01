// Created by harman on 1/11/25.
//Selection Sort

#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printarr(int arr[],int n)
{
    for (int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}
void selectionsort(int arr[],int n)
{
    for (int i =0;i<n-1;i++)
    {
        int min_index = i;
        for (int j =i+1;j<n;j++)
        {
            if ( arr[j]<arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index],&arr[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selectionsort(arr,n);
    cout<<"Sorted array :";
    printarr(arr,n);

}