#include<stdio.h>

int recursive(int arr[], int beg, int end, int key){
    if (beg > end)
        return -1;

    int mid = (beg + end) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return recursive(arr, beg, mid - 1, key);
    else
        return recursive(arr, mid + 1, end, key);
}

int iterative(int arr[], int beg, int end, int key){
    while(beg <= end){
        int mid = (beg + end) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -2;
}

int main(){
    int n, item;
    printf("enter total number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter array elemetns: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("enter element to search: ");
    scanf("%d", &item);

    int result = iterative(arr, 0, n - 1, item);
    int output = recursive(arr, 0, n - 1, item);

    if(result == -2)
        printf("element not found!\n");
    else
        printf("element %d found at index %d\n", item, result);

    if(output == -1)
        printf("element not found!!\n");
    else
        printf("element %d found at index %d\n", item, output);

    return 0;
}
