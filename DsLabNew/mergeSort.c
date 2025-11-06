#include<stdio.h>

void merge(int arr[], int l, int m, int h){
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[l + i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }

    int i = 0 , j = 0, k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h){
    if(l<h){
    int m = (l+h)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, h);
    merge(arr, l, m, h);
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
    
    mergeSort(arr, 0, n-1);

    printf("sorted array: ");
    for(int k =0; k<n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}