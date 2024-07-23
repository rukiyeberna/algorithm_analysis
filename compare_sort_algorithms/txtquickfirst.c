#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub) 
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) 
    {
        while (start < ub && a[start] <= pivot) 
        {
            start++;
        }
        while (end >= lb && a[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        
        {
            swap(&a[start], &a[end]);
        }
    }

    if (start == end) 
    {
        return start; // start ve end eşitse pivot noktasını döndür
    } else 
    {
        swap(&a[lb], &a[end]);
        return end; // pivot noktası
    }
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

double measureTime(int arr[], int arrSize) 
{
    clock_t start = clock();
    quickSort(arr, 0, arrSize - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void readArrayFromFile(const char *filename, int **arr, int *arrSize) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Dosya açılamadı.");
        return;
    }

    int size = 0;
    while (fscanf(file, "%d", &size) == 1) 
    {
        (*arrSize)++;
    }

    rewind(file); // Dosyanın başına geri dön

    *arr = (int *)malloc((*arrSize) * sizeof(int));
    if (*arr == NULL) 
    {
        printf("Bellek tahsis edilemedi.");
        fclose(file);
        return;
    }

    for (int i = 0; i < *arrSize; i++) 
    {
        if (fscanf(file, "%d", &(*arr)[i]) != 1)
         {
            printf("Dosya okunurken bir hata oluştu.");
            fclose(file);
            free(*arr); 
            *arrSize = 0;
            return;
        }
    }

    fclose(file);
}

int main() 
{
    int *arr15K = NULL;
    int arrSize15K = 0;
    int *arr500K = NULL;
    int arrSize500K = 0;

   
    readArrayFromFile("A15.txt", &arr15K, &arrSize15K);
    readArrayFromFile("A500.txt", &arr500K, &arrSize500K);

    if (arrSize15K == 0 || arrSize500K == 0)
     {
        printf("Dosya okuma hatası.");
        if (arr15K != NULL) free(arr15K); 
        if (arr500K != NULL) free(arr500K); 
        return 1;
    }

    
    double time15K = measureTime(arr15K, arrSize15K);
    printf("15.000 elemanlı dizi sıralama süresi: %f saniye\n", time15K);

    double time500K = measureTime(arr500K, arrSize500K);
    printf("500.000 elemanlı dizi sıralama süresi: %f saniye\n", time500K);

    free(arr15K);
    free(arr500K); 

    return 0;
}
