#include<stdio.h>

int main(){

    int n, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<n-1;i++){

        int minIndex = i;

        for(j=i+1;j<n;j++){
            if(array[j]<array[minIndex]){
                minIndex=j;
            }
        }
        int temp = array[i];
        array[i]=array[minIndex];
        array[minIndex]=temp;
    }

    printf("Sorting completed successfully.\n");
    printf("Sorted array:\n");

    for(i=0;i<n;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}      