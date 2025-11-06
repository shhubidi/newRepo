#include<stdio.h>

void selection(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printf("pass %d: ", i+1);
        for(int k=0; k<n; k++){
            printf("%d", arr[k]);
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
    selection(arr, n);
    return 0;
}
