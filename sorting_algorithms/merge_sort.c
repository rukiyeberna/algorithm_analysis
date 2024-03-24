/*pseudo code 
//A array, lb lower bound, ub upper bound
mergeSort(A,lb,ub)
{
    if(lb<ub)
    {
        {
            mid=(lb+ub)/2
            mergeSort(A,lb,mid)
            mergeSort(A,mid+1,ub)
            merge(A,lb,mid,ub)
        }
    }
}
merge(a,lb,mid,ub)
{
    i=lb;
    j=mid +1;
    k=lb;
    while(i<=mid&& j<=ub)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = a[j]; j ++; k++
        }
    }
    else 
    {
        while(i<=mid)
        {
            b[k] = a[i],i++;k++
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]= b[k];
    }
}



*/

#include <stdio.h>
#include <stdlib.h> 

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb;
    int *b = (int *)malloc((ub + 1) * sizeof(int)); // Dinamik bellek tahsisi
    if (b == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++) {
        a[k] = b[k];
    }

    free(b); 
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
        printf("Step: ");
        printArray(a + lb, ub - lb + 1);
    }
}

int main() {
    int A[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Unsorted array: ");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Sorted array in ascending order: ");
    printArray(A, n);

    return 0;
}
