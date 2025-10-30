// Created by harman on 30/10/25.
//Linear Search
#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
          if(arr[i]==key)
          {
              return i;
          }
               return -1;
}
int main()
{
   int n,arr[n],key;
   cout<<"Enter the number of elements:";
    cin>>n;
for(int i =0;i<n;i++)
{
  cin>>arr[i];
}
    cout<<"Enter the element to be search :";
    cin>>key;
int result = linearsearch(arr,n,key);
    (result==-1) ?cout<<"Element not found":cout<<"Element found at :"<<result+1;

return 0;
}

