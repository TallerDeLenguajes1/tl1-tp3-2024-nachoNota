#include <stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
    char *buff = (char *)malloc(50 * sizeof(char));
    char **nombre = (char **)malloc(5 * sizeof(char)); //reservo 5 espacios
    
    for (int i = 0; i < 5; i++)
    {
        printf("\nIngrese nombre: ");
        gets(buff);

        nombre[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombre[i], buff);
    }

    for (int i = 0; i < 5; i++)
    {
        puts(nombre[i]);
    }

    free(buff);
    for (int i = 0; i < 5; i++)
    {
        free(nombre[i]);
    }
    free(nombre);
}
