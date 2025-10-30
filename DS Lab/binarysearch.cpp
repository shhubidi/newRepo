// Created by harman on 30/10/25.
//binary search
#include <iostream>
using namespace std;

int binarysearch(int arr[],int n, int key)
{
    int l = 0;
    int h = n;
    while (l<=h)
    {
        int mid = (l+h)/2;
        if (arr[mid]==key)
            return mid;
        if (arr[mid]>key)
            h = mid - 1;
         else
            l = mid + 1;
    }
    return -1;
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
    cout<<"Enter the element to search :";
    cin>>key;
    int result = binarysearch(arr,n,key);
    (result==-1)?cout<<"Element not found":cout<<"Element found at:"<<result+1;

    return 0;
}
