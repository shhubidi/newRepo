#include<stdio.h>

void bubble(int arr[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("pass %d: ", i+1);
        for(int k=0; k<n; k++){
        printf("%d ", arr[k]);
        }
    printf("\n");
    }
    
}

int main(){
    int n;
    printf("enter total number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter array elemetns: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("after sorting: ");
    bubble(arr, n);
    return 0;
}