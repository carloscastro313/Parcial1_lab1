#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abmPelicula.h"
#include "informarPeliculas.h"
#define TRUE 0
#define FALSE 1

void peliculas_mostrar(ePelicula list[], eFecha listFecha[], eActores listActores[],  eGenero listGeneros[], int len, int flag)
{

    if(flag!=0)
    {
        peliculas_ordenarVector(list, listFecha, len);
        peliculas_ordenarVectorActores(listActores, 10);
        peliculas_cargarDatos(list, listFecha, listActores, listGeneros, len);
        peliculas_cargarDatosActores(listActores);
        peliculas_maximoGenero(list, listGeneros, len);
        peliculas_maximoActor(list, listActores, len);
        peliculas_maximoAnio(list, listFecha, len);
        system("pause");

    }
    else
    {
        printf("No hay datos ingresados\n");
        system("pause");

    }

}


void peliculas_ordenarVector(ePelicula list[], eFecha listFecha[], int len)
{
    int i,j, DDMMYY[len], auxDDMMYY;

    for(i=0; i<len-1; i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            DDMMYY[i]=(listFecha[i].anio*100+listFecha[i].mes)*100+listFecha[i].dia;
        }
    }

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len ; j++)
        {
            if(list[j].isEmpty==FALSE&&list[i].isEmpty==FALSE)
            {
                if(DDMMYY[i]<DDMMYY[j])
                {
                    peliculas_ordenamiento(list, listFecha, i, j);

                    auxDDMMYY=DDMMYY[i];
                    DDMMYY[i]=DDMMYY[j];
                    DDMMYY[j]=auxDDMMYY;

                }
            }
        }
    }
}



void peliculas_ordenamiento(ePelicula list[], eFecha listFecha[], int i, int j)
{

    char auxC[51];
    int auxE;

    auxE=list[i].id;
    list[i].id=list[j].id;
    list[j].id=auxE;

    auxE=list[i].idGenero;
    list[i].idGenero=list[j].idGenero;
    list[j].idGenero=auxE;

    auxE=list[i].idActor;
    list[i].idActor=list[j].idActor;
    list[j].idActor=auxE;

    strcpy(auxC,list[i].name);
    strcpy(list[i].name,list[j].name);
    strcpy(list[j].name,auxC);

    auxE=listFecha[i].id;
    listFecha[i].id=listFecha[j].id;
    listFecha[j].id=auxE;

    auxE=listFecha[i].dia;
    listFecha[i].dia=listFecha[j].dia;
    listFecha[j].dia=auxE;

    auxE=listFecha[i].mes;
    listFecha[i].mes=listFecha[j].mes;
    listFecha[j].mes=auxE;

    auxE=listFecha[i].anio;
    listFecha[i].anio=listFecha[j].anio;
    listFecha[j].anio=auxE;
}

void peliculas_ordenarVectorActores(eActores listActores[], int len)
{
    int i,j;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len ; j++)
        {
            if(stricmp(listActores[i].actorName,listActores[j].actorName)>0)
            {
                peliculas_ordenamientoActores(listActores, i, j);

            }
        }
    }
}

void peliculas_ordenamientoActores(eActores listActores[], int i, int j)
{

    char auxC[51];
    int auxE;

    auxE=listActores[i].id;
    listActores[i].id=listActores[j].id;
    listActores[j].id=auxE;

    strcpy(auxC,listActores[i].actorName);
    strcpy(listActores[i].actorName,listActores[j].actorName);
    strcpy(listActores[j].actorName,auxC);

    strcpy(auxC,listActores[i].origen);
    strcpy(listActores[i].origen,listActores[j].origen);
    strcpy(listActores[j].origen,auxC);


}

void peliculas_cargarDatos(ePelicula list[], eFecha listFecha[], eActores listActores[], eGenero listGenero[], int len)
{
    int i;

    printf("ID   |Titulo                    |estreno       |Actor                |Genero\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            peliculas_desplegarDatos(list[i], listFecha[i], listActores, listGenero);

        }
    }


}

void peliculas_desplegarDatos(ePelicula list, eFecha listFecha, eActores listActores[], eGenero listGenero[])
{
    int i;
    char actor[51], genero[51];

    for(i=0; i<10; i++)
    {
        if(list.idActor==listActores[i].id)
        {
            strcpy(actor,listActores[i].actorName);
            break;

        }
    }

    for(i=0; i<5; i++)
    {
        if(list.idGenero==listGenero[i].id)
        {
            strcpy(genero,listGenero[i].genero);
            break;

        }
    }

    printf("%3d |%25s |%2d/%2d/%7d |%20s |%8s\n", list.id, list.name, listFecha.dia, listFecha.mes, listFecha.anio, actor, genero);

}

void peliculas_cargarDatosActores(eActores listActores[])
{
    int i;
    printf("\nID |Actor                     |Pais\n");


    for(i=0; i<10; i++)
    {
        peliculas_desplegarDatosActores(listActores[i]);
    }


}
void peliculas_desplegarDatosActores(eActores listActores)
{
    char actor[51], pais[20];

    strcpy(actor,listActores.actorName);
    strcpy(pais,listActores.origen);
    printf("%2d |%25s |%20s\n", listActores.id, actor, pais);

}

void peliculas_maximoGenero(ePelicula list[], eGenero listGenero[], int len)
{
    int contador, maximo, i, j, flag;
    char genero[100];
    flag=0;


    for(j=0;j<6;j++)
    {
        contador=0;
        for(i=0;i<len;i++)
        {
            if(list[i].idGenero==listGenero[j].id)
            {
                contador++;
            }
        }
        if(flag==0||contador>maximo)
        {
            strcpy(genero,listGenero[j].genero);
            maximo=contador;
            flag=1;
        }else
        {
            if(contador==maximo)
            {
                strcat(genero," y ");
                strcat(genero,listGenero[j].genero);
            }

        }
    }


    printf("\n\nEl genero con mas peliculas es %s con %d ", genero, maximo);

}


void peliculas_maximoActor(ePelicula list[], eActores listActores[], int len)
{
    int contador, maximo, i, j;
    char actor[1000];

    maximo=0;

    for(j=0;j<10;j++)
    {
        contador=0;
        for(i=0;i<len;i++)
        {
            if(list[i].idActor==listActores[j].id&&list[i].isEmpty==FALSE)
            {
                contador++;
            }
        }
        if(contador>maximo)
        {
            maximo=contador;
            strcpy(actor,listActores[j].actorName);

        }else
        {
            if(contador==maximo)
            {
                strcat(actor," y ");
                strcat(actor,listActores[j].actorName);
            }
        }

    }

    printf("\n\nEl actor con mas peliculas es %s con %d ", actor, maximo);

}
void peliculas_maximoAnio(ePelicula list[], eFecha listFecha[], int len)
{
    int contador, maximo, i, j, indice, flag;
    int anioAux[10];
    maximo=0;
    indice=0;
    flag=0;

    for(i=0;i<10;i++)
    {
        anioAux[i]=0;

    }

    for(j=1900;j<2100;j++)
    {
        contador=0;
        for(i=0;i<len;i++)
        {
            if(listFecha[i].anio==j&&list[i].isEmpty==FALSE)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            if(indice>0&&flag==1)
            {
                for(i=0;i<10;i++)
                {
                    anioAux[i]=0;

                }
                indice=0;
            }
            anioAux[0]=j;
            maximo=contador;
            flag=1;

        }else
        {
            if(contador==maximo)
            {
                indice++;
                anioAux[indice]=j;

            }
        }
    }


    printf("\n\nSe filmaron un total de %d peliculas en los anio ", maximo);
    for(i=0;i<10;i++)
    {
        if(anioAux[i]!=0)
        {
            printf("|%d ", anioAux[i]);
        }
    }
    printf("\n");
}
