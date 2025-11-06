#include<stdio.h>

void swap(int arr[], int l, int h){
    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
}

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i<j){
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i < j){
            swap(arr, i, j);
        }
    }
    swap(arr, l, j);
    return j;
}

void quickSort(int arr[], int l, int h){
    if(l < h){    
        int p = partition(arr, l, h);
        quickSort(arr, l, p);
        quickSort(arr, p+1, h);
    }
}

int main(){
    int n;
    printf("enter number of terms: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter array elements: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n);
    printf("sorted array: ");
    for(int k =0; k<n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}