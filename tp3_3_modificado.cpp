#include <stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
    char *buff = (char *)malloc(50 * sizeof(char));
    
    int cant;
    printf("\nIngrese cantidad de nombres: ");
    scanf("%d", &cant);

    char **nombre = (char **)malloc(cant * sizeof(char));

    for (int i = 0; i < cant; i++)
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
    for (int i = 0; i < cant; i++)
    {
        free(nombre[i]);
    }
    free(nombre);
}
