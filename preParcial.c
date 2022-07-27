#include <stdio.h>         //Ejercicio Integrador 5 
#include <stdlib.h>        //Alumno: 
#define TAM 5              //Turno: 

struct pedido
{
    int nroPedido; 
    int destino; 
    int hora;
    int estado;
    float peso;
};
// prototipos de las funciones
int menu();
void seleccionOpcion(struct pedido Pedidos[],int opc);
void cargarEnviosPlanificados(struct pedido Pedidos[]);
void mostrarEnviosPlanificados(struct pedido Pedidos[]);
void modificarEnvio(struct pedido Pedidos[]);
void mostrarEnviosDestino(struct pedido Pedidos[]);
void mostrarEnviosPendientes(struct pedido Pedidos[]);
void mostrarEnviosDespachados(struct pedido Pedidos[]);
void mostrarEnvioMayorPeso(struct pedido Pedidos[]);
void mostrarEnviosMenorPeso(struct pedido Pedidos[]);

int ingresoEntero(char cadena[], int a, int b);
float ingresoReal(char cadena[], float a, float b);

int main()
{
    int opc;    
    struct pedido Pedidos[TAM];

    while(opc!= 0)
    {
        opc = menu();                     

        seleccionOpcion(Pedidos, opc);
    }
    if (opc == 0)
    {
        printf("Saliendo del programa...\n");
    }
   return 0;
}
int menu()
{
    int opc;  
    system("cls");
    printf("Menu de opciones\n");
    printf("1 - Cargar env%cos planificados\n", 161);
    printf("2 - Mostrar env%cos planificados\n", 161);
    printf("3 - Modificar estado de un envio\n", 161);
    printf("4 - Mostrar env%cos\n", 161);
    printf("5 - Mostrar env%cos pendientes\n", 161);
    printf("6 - Mostrar env%cos despachados\n", 161);
    printf("7 - Mostrar env%cio con mayor peso\n", 161);
    printf("8 - Mostrar env%cio con menor peso\n", 161);
    printf("0 - Salir.\n");
    
    do
    {
        printf("Ingrese la opcion:");
        scanf("%d", &opc);
    } while (opc < 0 || opc > 8);
  
    
    return opc;
}
void seleccionOpcion(struct pedido Pedidos[],int opc)
{
    switch (opc)
    {
        case 1:
            cargarEnviosPlanificados(Pedidos);
            break;

        case 2:
            mostrarEnviosPlanificados(Pedidos);
            break;
        
        case 3:
            modificarEnvio(Pedidos);
            break;
        case 4:
            mostrarEnviosDestino(Pedidos);
            break;
        case 5:
            mostrarEnviosPendientes(Pedidos);
            break;    
        case 6:
            mostrarEnviosDespachados(Pedidos);
            break;
        case 7:
            mostrarEnvioMayorPeso(Pedidos);
            break;
        case 8:
            mostrarEnviosMenorPeso(Pedidos);
            break;            
    }
    return;
}
void cargarEnviosPlanificados(struct pedido Pedidos[])
{
    int np, destino, hora, estado;
    float peso;
    
    printf("Ingreso de datos de pedidos\n");
    for(int i = 0; i < TAM; i++)
    {
        system("cls");
        np = ingresoEntero("el numero de pedido", 100, 999);
        Pedidos[i].nroPedido = np;

        peso = ingresoReal("el peso", 0.1, 50.0);
        Pedidos[i].peso = peso;

        printf("Localidades de envio\n");
        printf("1 - Rosario\n");
        printf("2 - Funes\n");
        printf("3 - Roldan\n");
        printf("4 - Baigorria\n");
        destino = ingresoEntero("el destino(1-4)", 1, 4);
        Pedidos[i].destino = destino;
        
        hora = ingresoEntero("la hora de despacho (8-22)", 8, 22);
        Pedidos[i].hora = hora;
        
        estado = ingresoEntero("el estado del pedido", 0, 1);
        Pedidos[i].estado = estado;
    }
    return;
}
void mostrarEnviosPlanificados(struct pedido Pedidos[])
{
    system("cls");
    printf("Mostrar los pedidos del dia:\n");

    for(int i = 0; i < TAM; i++)
    {
        printf("Numero de pedido: %d \n", Pedidos[i].nroPedido);
        printf("Peso del pedido: %.2f KL\n", Pedidos[i].peso);
        if (Pedidos[i].destino == 1)
        {
            printf("Destino del pedido: Rosario \n");
        }
        else if (Pedidos[i].destino == 2)
        {
            printf("Destino del pedido: Funes\n");
        }
        if (Pedidos[i].destino == 3)
        {
            printf("Destino del pedido: Roldan\n");
        }
        else if (Pedidos[i].destino == 4)
        {
            printf("Destino del pedido: Baigorria\n");
        }
        
        printf("Hora de despacho: %d Hs\n", Pedidos[i].hora);
        if (Pedidos[i].estado == 1)
        {
            printf("Estado del pedido: Despachado \n");
        }
        else
        {
            printf("Estado del pedido: Pendiente\n");
        }
        printf("--------------------\n");
    }
    getch();
    return;
}
void modificarEnvio(struct pedido Pedidos[])
{
    int np;
    int i = 0;
    system("cls");
    printf("Ingrese el numero del pedido a modificar: ");
    scanf("%d", &np);

    while(Pedidos[i].nroPedido != np)
    {
        i++;
    }
    printf("Estado del pedido: %d \n\n", Pedidos[i].estado);

    printf("Ingrese el nuevo estado del pedido (1 - 0):");
    scanf("%d", &Pedidos[i].estado);

    return;
}
void mostrarEnviosDestino(struct pedido Pedidos[])
{
    system("cls");
    printf("Mostrar Tabla de pedidos del dia:\n\n");

    printf("Numero  ||  Peso  ||  Destino  ||  Hora  ||  Estado del pedido \n");

    for(int i = 0; i < TAM; i++)
    {
        printf("%d     || %.2f  ||  %d        || ", Pedidos[i].nroPedido, Pedidos[i].peso, Pedidos[i].destino);
        printf("%d     ||      %d \n", Pedidos[i].hora, Pedidos[i].estado);
    }

    getch();
    return;
}
void mostrarEnviosPendientes(struct pedido Pedidos[])
{
    int pendientes = 0;
    system("cls");
    printf("Env%cos pendientes\n\n", 161);

    for (int i = 0; i < TAM; i++)
    {
        if(Pedidos[i].estado == pendientes)
        {
            printf("Numero de pedido: %d \n", Pedidos[i].nroPedido);
            printf("Peso del pedido: %.2f Kl\n", Pedidos[i].peso);
            if (Pedidos[i].destino == 1)
            {
                printf("Destino del pedido: Rosario \n");
            }
            else if (Pedidos[i].destino == 2)
            {
                printf("Destino del pedido: Funes\n");
            }
            if (Pedidos[i].destino == 3)
            {
                printf("Destino del pedido: Roldan\n");
            }
            else if (Pedidos[i].destino == 4)
            {
                printf("Destino del pedido: Baigorria\n");
            }
            printf("Hora de despacho: %d Hs\n", Pedidos[i].hora);
            printf("Estado del pedido: Pendiente\n");
            printf("--------------------\n");
        } 
    }
    getch();
    return;
}
void mostrarEnviosDespachados(struct pedido Pedidos[])
{
    int despachado = 1;
    system("cls");
    printf("Env%cos despachados\n\n", 161);

    for (int i = 0; i < TAM; i++)
    {
        if(Pedidos[i].estado == despachado)
        {
            printf("Numero de pedido: %d \n", Pedidos[i].nroPedido);
            printf("Peso del pedido: %.2f Kl\n", Pedidos[i].peso);
            if (Pedidos[i].destino == 1)
            {
                printf("Destino del pedido: Rosario \n");
            }
            else if (Pedidos[i].destino == 2)
            {
                printf("Destino del pedido: Funes\n");
            }
            if (Pedidos[i].destino == 3)
            {
                printf("Destino del pedido: Roldan\n");
            }
            else if (Pedidos[i].destino == 4)
            {
                printf("Destino del pedido: Baigorria\n");
            }
            printf("Hora de despacho: %d Hs\n", Pedidos[i].hora);
            printf("Estado del pedido: Despachado\n");
            printf("--------------------\n");
        } 
    }
    getch();
    return;
}
void mostrarEnvioMayorPeso(struct pedido Pedidos[])
{
    system("cls");
    int i = 0;
    float mayorPeso = 0;
    int numPedido = 0;
    mayorPeso = Pedidos[i].peso;
    numPedido = Pedidos[i].nroPedido;
    for (int i = 0 ; i < TAM; i++)
    {
        if (Pedidos[i].peso > mayorPeso) 
        {
            mayorPeso = Pedidos[i].peso;
            numPedido = Pedidos[i].nroPedido;
        }
    }
    printf("El pedido con mayor peso es: %d \n", numPedido);
    printf("Peso del pedido: %.2f KL\n", mayorPeso);
    getch();
    return;
}
void mostrarEnviosMenorPeso(struct pedido Pedidos[])
{
    system("cls");
    int i = 0;
    float menorPeso = 0;
    int numPedido =0;

    menorPeso = Pedidos[i].peso;
    numPedido = Pedidos[i].nroPedido;

    for ( i; i < TAM; i++)
    {
        if(Pedidos[i].peso < menorPeso)
        {
            menorPeso = Pedidos[i].peso;
            numPedido = Pedidos[i].nroPedido;
        }
    }
    printf("El pedido con menor peso es: %d\n", numPedido);
    printf("Peso del pedido: %.2f Kl\n", menorPeso);
    getch();
    return;
}
int ingresoEntero(char cadena[], int a, int b)
{
    int res;
    do
    {
        printf("Ingrese %s: ", cadena);
        scanf("%d", &res);
    } while (res < a || res > b);

    return res;
}
float ingresoReal(char cadena[], float a, float b)
{
    float res;
    do
    {
        printf("Ingrese %s: ", cadena);
        scanf("%f", &res);
    } while (res < a || res > b);

    return res;
}