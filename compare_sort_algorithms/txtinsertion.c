
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_15K 15000
#define ARRAY_SIZE_500K 500000

void insertionSort(int arr[], int arrSize) 
{
    int i, j, temp;
    
    for (i = 1; i < arrSize; i++) 
    {
        temp = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = temp;
    }
}

double measureTime(int arr[], int arrSize, void (*sortFunc)(int[], int)) 
{
    clock_t start = clock();
    sortFunc(arr, arrSize);
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
    int arr15K[ARRAY_SIZE_15K];
    int arr500K[ARRAY_SIZE_500K];

    
    readArrayFromFile("A15.txt", arr15K, ARRAY_SIZE_15K);
    readArrayFromFile("A500.txt", arr500K, ARRAY_SIZE_500K);

    double time15K = measureTime(arr15K, ARRAY_SIZE_15K, insertionSort);
    printf("15.000 elemanlı dizi sıralama süresi: %f saniye\n", time15K);

    double time500K = measureTime(arr500K, ARRAY_SIZE_500K, insertionSort);
    printf("500.000 elemanlı dizi sıralama süresi: %f saniye\n", time500K);

    return 0;
}

