#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_15K 15000
#define ARRAY_SIZE_500K 500000

void randomArrayMaker(const char *filename, int size )
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Dosya oluşturulamadı.");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) 
    {
        int num = rand() % 20 + 1; // 1 ile 20 arasında rastgele sayı üret
        fprintf(file, "%d\n", num);
    }

    fclose(file);

}

int main() 
{
    randomArrayMaker("A15.txt", ARRAY_SIZE_15K);
    randomArrayMaker("A500.txt", ARRAY_SIZE_500K);

    printf("Dosyalar oluşturuldu: A15.txt ve A500.txt\n");
    return 0;
}


