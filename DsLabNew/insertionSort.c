#include<stdio.h>

void insertion(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;

        printf("after pass %d: ", i);
        for(int k=0; k<n; k++){
            printf("%d", arr[k]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("enter array elements: ");
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("sorted array is: \n");
    insertion(arr,n);

    return 0;
}