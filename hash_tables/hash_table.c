#include <string.h> 
#include <stdio.h>


#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct 
{
    char name[MAX_NAME];
    int age;
}person;

unsigned int hash(char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;

    for(int i=0;i<length;i++)
    {
        hash_value+= name[i];
        hash_value 
    }
    return hash_value;
   // return 5;
}

int main()
{
    printf("ayse => %u\n",hash("ayse"));
    printf("mehmet => %u\n", hash("mehmet"));
    printf("elif => %u\n", hash("elif"));
    printf("ali => %u\n", hash("ali"));
    printf("fatma => %u\n", hash("fatma"));
    
    return 0;
}