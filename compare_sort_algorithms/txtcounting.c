#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_15K 15000
#define ARRAY_SIZE_500K 500000
void countingSort(int a[], int n, int k) 
{
    int *count = (int *)malloc((k + 1) * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    if (count == NULL || b == NULL) 
    {
        printf("Bellek tahsis edilemedii.\n");
        exit(1);
    }

    for (int i = 0; i <= k; i++) 
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= k; i++) 
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        b[--count[a[i]]] = a[i];
    }

    printf("Counting Sort ile sıralanmış array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    free(count);
    free(b);
}

double measureTimeForCountingSort(int arr[], int arrSize, int k) 
{
    clock_t start = clock();
    countingSort(arr, arrSize, k);
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
    int arr15K_Counting[ARRAY_SIZE_15K];
    int arr500K_Counting[ARRAY_SIZE_500K];

    readArrayFromFile("A15.txt", arr15K_Counting, ARRAY_SIZE_15K);
    readArrayFromFile("A500.txt", arr500K_Counting, ARRAY_SIZE_500K);
 
    double time15K_Counting = measureTimeForCountingSort(arr15K_Counting, ARRAY_SIZE_15K, 20);
    double time500K_Counting = measureTimeForCountingSort(arr500K_Counting, ARRAY_SIZE_500K, 20);
    printf("\nCounting Sort ile sıralama süreleri:\n");
    printf("15.000 elemanlı dizi için: %f saniye\n", time15K_Counting);
    printf("500.000 elemanlı dizi için: %f saniye\n", time500K_Counting);

    return 0;
}
