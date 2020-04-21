#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto
{
    int ProductoID;//Numerado en ciclo iterativo
    int Cantidad;// entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente
{
    int ClienteID;    // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         //El tamaño de este arreglo depende de la variable
                                // "CantidadProductosAPedir"
};

void cargaClientes(Cliente * pntClientes, int cantClientes);
int cargaProductos(int prodID,Producto * pntProducto, int productosAPedir);

int main(){
    srand(time(NULL));
    int cantClientes;
    printf("Cuantos clientes desea ingresar?: ");
    scanf("%d",&cantClientes);
    system("cls");
    Cliente * pntCliente = (Cliente *) malloc(sizeof(Cliente)*cantClientes);
    cargaClientes(pntCliente,cantClientes);
    free(pntCliente);

    getchar();
    getchar();
    return 0;
}

void cargaClientes(Cliente * pntClientes, int cantClientes){
    int prodID = 0; //auxiliar
    for (int i = 0; i < cantClientes; i++)
    {
        char nombre[80]; //auxiliar
        printf("Nombre del Cliente: ");
        scanf("%s",nombre);
        system("cls");
        (pntClientes + i)->ClienteID = i;
        (pntClientes + i)->NombreCliente = (char*)malloc(sizeof(nombre)*(strlen(nombre)));
        strcpy((pntClientes + i)->NombreCliente,nombre);

        int productosAPedir = rand() % 5 + 1;  //aleatorio
        (pntClientes + i)->CantidadProductosAPedir = productosAPedir;
        (pntClientes + i)->Productos = (Producto *)malloc(sizeof(Producto)*productosAPedir);
        prodID = cargaProductos(prodID,(pntClientes + i)->Productos,productosAPedir);
    }
}

int cargaProductos(int prodID,Producto * pntProducto, int productosAPedir){
    for (int i = 0; i < productosAPedir; i++)
    {
        prodID++;
        (pntProducto + i)->ProductoID = prodID;
        (pntProducto + i)->Cantidad = rand() % 10 + 1;
        (pntProducto + i)->PrecioUnitario = rand() % 100 + 10;
        (pntProducto + i)->TipoProducto = TiposProductos[i];
    }
    return prodID;
}
