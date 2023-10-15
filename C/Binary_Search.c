#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
 
int read_array(int arr[],int n){
    for (int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}


int main()
{
    int arr[100];
    int n,x;
    printf("Size of Array:");
    scanf("%d",&n);
    printf("Array Elements:");
    read_array(arr,n);
    printf("Element to Find:");
    scanf("%d",&x);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is NOT present in array") : printf("Element is present at index %d",result);
    return 0;
}