#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FILA 5
#define COL 12

int min = 10000, max = 50000;

void mostrar(int mattriz[FILA][COL]);
void promedio_por_anio(int matriz[FILA][COL]);
void mayor_menor_prod(int matriz[FILA][COL]);

main(){
    srand(time(NULL));

    int mat[FILA][COL];
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < COL; j++)
        {
            mat[i][j] = rand() % (max + 1) + min;
        }
    }

    mostrar(mat);
    mayor_menor_prod(mat);
    promedio_por_anio(mat);
    
}

void mostrar(int matriz[FILA][COL]){
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < COL; j++)
        {
            printf("%d - ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedio_por_anio(int matriz[FILA][COL]) {
    int i, j, sum = 0;
    float prom = 0;
    for (i = 0; i < FILA; i++) {
        for (j = 0; j < COL; j++) {
            sum += matriz[i][j];
        }
        sum /= COL;
        prom = sum / COL;
        printf("\nPromedio del anio %d: %.2f", i + 1 + 2024, prom);
    }
}

void mayor_menor_prod(int matriz[FILA][COL]){
    int may = 0, men = 0, anio_may = 0, mes_may = 0, anio_men = 0, mes_men = 0;

        for (int i = 0; i < FILA; i++){
            for (int j = 0; j < COL; j++)
            {
                if(matriz[i][j] > may){
                    may = matriz[i][j];
                    anio_may = i;
                    mes_may = j;
                }

                if(matriz[i][j] < men){
                    men = matriz[i][j];
                    anio_men = i;
                    mes_men = j;
                }
            }
        }

    printf("\nEn el mes %d y dentro de %d anios se produciria la mayor produccion", mes_may + 1, anio_may + 1);
    printf("\nEn el mes %d y dentro de %d anios se produciria la menor produccion", mes_men + 1, anio_men + 1);
}


