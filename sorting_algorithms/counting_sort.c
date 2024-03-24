/*
pseudo code 
k = key
CountSort(a,n,k)
{
    int Count[k+1], b[n]
    for(i=0;i<n;i++)
    {
        Count[a[i]]++;
    }
    for(i=1;i<=k;i++)
    {
        Count[i]=Count[i] +Count[i-1];
    }
    for(i=n-1;i>=0;i++)
    {
        b[--Count[a[i]]]= a[i]
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}


*/
#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[], int n, int k) {
    int *count = (int *)malloc((k + 1) * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    if (count == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }


    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    printf("Count array before incrementing: ");
    for (int i = 0; i <= k; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

  
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }


    printf("Count array after incrementing: ");
    for (int i = 0; i <= k; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

   
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }

    printf("Count array after modification: ");
    for (int i = 0; i <= k; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

   
    for (int i = n - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }


    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

   
    free(count);
    free(b);
}

int main() {
    int A[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 9; 

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    countingSort(A, n, k);

    return 0;
}
