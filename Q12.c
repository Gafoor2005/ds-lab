#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    for(int i = n/2 - 1; i >= 0;i--){
        heapify(arr,n,i);
    }
    for(int i = n-1; i >= 0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int arr[30],i,n;
    printf("enter no of elements in BT: ");
    scanf("%d",&n);
    printf("enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    printf("sorted array:\n");
    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }  
    return 0;
}
// output:
// enter no of elements in BT: 6
// enter elements:
// 10 24 14 52 15 22
// sorted array:
// 10 14 15 22 24 52





//     0
//    / \
//   1   2
//  / \  
// 3   4