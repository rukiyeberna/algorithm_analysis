#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub) {
    int pivot = a[ub]; // Pivotu son eleman oldu
    int start = lb;
    int end = ub - 1; // Son eleman pivot olduğu için sondan bir önceki indekse kadar git

    while (start <= end) {
        while (start <= end && a[start] <= pivot) {
            start++;
        }
        while (start <= end && a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[start], &a[ub]); // Pivotu doğru konuma yerleştir
    return start;
}

void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        printf("Step: ");
        for (int i = lb; i <= ub; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int main() {
    int A[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}