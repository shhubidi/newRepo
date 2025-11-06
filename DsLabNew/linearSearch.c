#include<stdio.h>

int main(){
    int n, flag, key, index;
    printf("enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("enter array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]); 
    }

    printf("enter element to search: ");
    scanf("%d", &key);
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            flag = 1;
            index = i;
        }
    }

    if(flag == 1){
        printf("element %d found at index %d", key, index);
    }
    else{
        printf("element not found");
    }
    
    return 0;
}