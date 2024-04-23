#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef producto;

struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef cliente;

void cargar_clientes(cliente *aux, int cant);
void mostrar_clientes(cliente *aux, int cant);
float costo_tot(producto *aux);

main(){

    srand(time(NULL));

    int cant_clientes;
    cliente *punt_cliente;
    bool bandera = true;

    while (bandera){
        printf("\nIngrese cantidad de clientes (5 maximo): ");
        scanf("%d", &cant_clientes);
        if(cant_clientes <= 5){
            bandera = false;
        } else {
            printf("\nIngresar 5 clientes maximo.");
        }
    }

    punt_cliente = (cliente *)malloc(sizeof(cliente) * cant_clientes);

    cargar_clientes(punt_cliente, cant_clientes);
    mostrar_clientes(punt_cliente, cant_clientes);

    free(punt_cliente);
}


void cargar_clientes(cliente *aux, int cant){
    for (int i = 0; i < cant; i++){
        printf("\n------Cliente %d------", i+1);
        aux->ClienteID = i+1;

        aux->NombreCliente = (char *)malloc(sizeof(char) * 50);
        printf("\nIngrese nombre del cliente: ");
        fflush(stdin);
        gets(aux->NombreCliente);
        fflush(stdin);
        
        aux->CantidadProductosAPedir = rand() % 5 + 1;
        
        aux->Productos = (producto *)malloc(sizeof(producto) * aux->CantidadProductosAPedir);

        for (int j = 0; j < aux->CantidadProductosAPedir; j++){
            
            aux->Productos[j].ProductoID = j+1;
            aux->Productos[j].Cantidad = rand() % 11 + 1;
            aux->Productos[j].TipoProducto = TiposProductos[rand() % 5];
            aux->Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
        
        aux++;
    }
    
}

void mostrar_clientes(cliente *aux, int cant){
    for (int i = 0; i < cant; i++){
        printf("\n------Cliente %d------", i+1);
        printf("\nNombre: %s", aux->NombreCliente);
        printf("\nProductos a pedir: %d", aux->CantidadProductosAPedir);
        for (int j = 0; j < aux->CantidadProductosAPedir; j++){
            printf("\n------Producto %d------", j+1);
            printf("\nCantidad: %d", aux->Productos[j].Cantidad);
            printf("\nTipo producto: %s", aux->Productos[j].TipoProducto);
            printf("\nPrecio unitario: %.2f", aux->Productos[j].PrecioUnitario);
            printf("\nCosto total producto %d: %.2f", aux->Productos[j].ProductoID, costo_tot(aux->Productos));
        }
        
        aux++;
    }
    
}

float costo_tot(producto *aux){
    return aux->Cantidad * aux->PrecioUnitario;
}
