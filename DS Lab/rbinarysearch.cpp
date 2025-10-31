// Created by harman on 31/10/25.
//recursion binary search
#include <iostream>
using namespace std;

int rbinarysearch(int arr[],int l,int h, int key)
{
    if (h>=l)
    {
        int mid = l +(h-l)/2;
        if (key==arr[mid])
        {
            return mid;
        }
        if (key>mid)
        {
            return rbinarysearch(arr,mid+1,h,key);
        }
        if (key<mid)
        {
            return rbinarysearch(arr,l,mid-1,key);
        }
    }
    else
    {
        return -1;
    }
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
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    int l = 0;
    int h = n-1;
    int result = rbinarysearch(arr,l,h,key);
    if (result == -1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at position: "<<result+1;
    }
    return 0;
}


