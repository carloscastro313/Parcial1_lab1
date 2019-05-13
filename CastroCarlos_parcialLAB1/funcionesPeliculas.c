#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abmPelicula.h"
#include "funcionesPeliculas.h"

char peliculas_opciones(char mensaje[])
{
    char opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");

    return opcion;
}

void peliculas_ingresoPalabra(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

    peliculas_correctorPalabras(buffer);

}
void peliculas_correctorPalabras(char buffer[])
{
    int i;

    strlwr(buffer);

    if(buffer[0]!='¿'||buffer[0]!='!')
    {
        buffer[0]=toupper(buffer[0]);

    }else
    {
        buffer[1]=toupper(buffer[1]);

    }

    for(i=0;i<51;i++)
    {
        if(buffer[i]==' ')
        {
            buffer[i+1]=toupper(buffer[i+1]);
        }
    }

}

int peliculas_ingresoNumero(char mensaje[])
{
    int bufferN;
    printf(mensaje);
    scanf("%d",&bufferN);

    return bufferN;
}
