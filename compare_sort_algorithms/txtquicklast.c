#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_15K 15000
#define ARRAY_SIZE_500K 500000

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub) 
{
    int pivot = a[ub]; // Pivotu son eleman olarak seç
    int start = lb;
    int end = ub - 1; // Son eleman pivot olduğu için sondan bir önceki indekse kadar git

    while (start <= end) 
    {
        while (start <= end && a[start] <= pivot) 
        {
            start++;
        }
        while (start <= end && a[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[start], &a[ub]); 
    return start;
}

void quickSort(int a[], int lb, int ub) 
{
    if (lb < ub) 
    {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

double measureTimeForQuickSort(int arr[], int arrSize) 
{
    clock_t start = clock();
    quickSort(arr, 0, arrSize - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void readArrayFromFile(const char *filename, int arr[], int arrSize) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Dosya açılamadı.");
        return;
    }

    for (int i = 0; i < arrSize; i++) 
    {
        if (fscanf(file, "%d", &arr[i]) != 1) 
        {
            printf("Dosya okunurken bir hata oluştu.");
            fclose(file);
            return;
        }
    }

    fclose(file);
}

int main() 
{
    int arr15K_Quick[ARRAY_SIZE_15K];
    int arr500K_Quick[ARRAY_SIZE_500K];


    readArrayFromFile("A15.txt", arr15K_Quick, ARRAY_SIZE_15K);
    readArrayFromFile("A500.txt", arr500K_Quick, ARRAY_SIZE_500K);

    
    double time15K_Quick = measureTimeForQuickSort(arr15K_Quick, ARRAY_SIZE_15K);
    double time500K_Quick = measureTimeForQuickSort(arr500K_Quick, ARRAY_SIZE_500K);
    printf("\nQuick Sort ile sıralama süreleri:\n");
    printf("15.000 elemanlı dizi için: %f saniye\n", time15K_Quick);
    printf("500.000 elemanlı dizi için: %f saniye\n", time500K_Quick);

    return 0;
}
