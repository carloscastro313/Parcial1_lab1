#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abmPelicula.h"
#include "informarPeliculas.h"
#include "funcionesPeliculas.h"
#define TRUE 0
#define FALSE 1


void peliculas_initFilms(ePelicula list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty=TRUE;

    }
}

int peliculas_alta(ePelicula list[], eFecha listFecha[], eActores listActores[], int len, int flag)
{
    int i;

    i=peliculas_buscarLibre(list, len);
    if(i!=-1)
    {
        list[i].id=i+1000;
        list[i].id=i+1000;

        peliculas_ingresoPalabra(list[i].name, "Ingrese titulo: ");

        printf("Ingrese la fecha de estreno: \n");
        listFecha[i].dia=peliculas_ingresoNumero("\nDia: ");
        while(listFecha[i].dia<0||listFecha[i].dia>31)
        {
            listFecha[i].dia=peliculas_ingresoNumero("\nReingrese Dia: ");
        }

        listFecha[i].mes=peliculas_ingresoNumero("\nMes: ");
        while(listFecha[i].mes<0||listFecha[i].mes>12)
        {
            listFecha[i].mes=peliculas_ingresoNumero("\nReingrese mes: ");

        }

        listFecha[i].anio=peliculas_ingresoNumero("\nAnio: ");
        while(listFecha[i].anio<0)
        {
            listFecha[i].anio=peliculas_ingresoNumero("\nReingrese nAnio: ");

        }
        printf("\nGeneros de pelicula\n\n1.Accion\n2.Comedia\n3.Drama\n4.Romance\n5.Terror\n");
        list[i].idGenero=peliculas_ingresoNumero("Ingrese genero: ");
        while(list[i].idGenero<0||list[i].idGenero>5)
        {
            list[i].idGenero=peliculas_ingresoNumero("Reingrese genero: ");

        }
        peliculas_cargarDatosActores(listActores);
        list[i].idActor=peliculas_ingresoNumero("Ingrese ID del actor: ");
        while(list[i].idActor<0||list[i].idActor>10)
        {
            list[i].idActor=peliculas_ingresoNumero("Reingrese ID del actor: ");

        }
        list[i].isEmpty=FALSE;

        flag=flag+1;

    }

    return flag;
}

int peliculas_buscarLibre(ePelicula list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            break;

        }

    }
    return i;
}
void peliculas_hardcodearDatos(ePelicula list[], eFecha listFecha[], int tam)
{
    int i;
    char nombres[][50]= {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13  Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity war","Grandes esperanzas","SWAT","XxX"};
    int idActores[22]= {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int sector[22]= {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int dia[22]= {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int mes[22]= {4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int anio[21]= {2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};

    for(i=0; i<21; i++)
    {
        list[i].id =1000+i;
        listFecha[i].id =1000+i;
        list[i].idActor = idActores[i];
        list[i].idGenero = sector[i];
        strcpy(list[i].name, nombres[i]);
        listFecha[i].mes = mes[i];
        listFecha[i].anio = anio[i];
        listFecha[i].dia = dia[i];
        list[i].isEmpty = FALSE;

    }
}
void peliculas_modificar(ePelicula list[], eFecha listFecha[], int len, int flag)
{
    int id, indice;
    char opcion;

    if(flag!=0)
    {
        id=peliculas_ingresoNumero("Ingrese id: ");

        indice=peliculas_findFilmsById(list, len, id);

        if(indice!=-1)
        {
            opcion=peliculas_opciones("Que desea cambiar?\n\n\n1.Titulo\n2.Fecha de estreno\n3.Actor\nSeleccion:");
            peliculas_opcionesCambio(list, listFecha, indice, opcion);

        }
        else
        {
            printf("No se encontro ID\n");

        }
    }
    else
    {
        printf("No hay datos ingresados\n");

    }
    system("pause");
}

int peliculas_findFilmsById(ePelicula list[], int len, int id)
{
    int indice, i;

    indice=-1;

    for(i=0; i<len; i++)
    {
        if(id==list[i].id&&list[i].isEmpty==FALSE)
        {
            indice=i;
            break;

        }
    }

    return indice;
}


void peliculas_opcionesCambio(ePelicula list[], eFecha listFecha[], int indice, char opcion)
{
    switch(opcion)
    {
    case'1':
        peliculas_ingresoPalabra(list[indice].name, "Ingrese nuevo Titulo: ");

        break;
    case'2':
        listFecha[indice].dia=peliculas_ingresoNumero("\nDia: ");
        while(listFecha[indice].dia<0||listFecha[indice].dia>31)
        {
            listFecha[indice].dia=peliculas_ingresoNumero("\nReingrese Dia: ");
        }

        listFecha[indice].mes=peliculas_ingresoNumero("\nMes: ");
        while(listFecha[indice].mes<0||listFecha[indice].mes>12)
        {
            listFecha[indice].mes=peliculas_ingresoNumero("\nReingrese mes: ");

        }

        listFecha[indice].anio=peliculas_ingresoNumero("\nAnio: ");
        while(listFecha[indice].anio<0)
        {
            listFecha[indice].anio=peliculas_ingresoNumero("\nReingrese nAnio: ");

        }

        break;
    case'3':
        list[indice].idActor=peliculas_ingresoNumero("Ingrese ID del actor: ");
        while(list[indice].idActor<0||list[indice].idActor>10)
        {
            list[indice].idActor=peliculas_ingresoNumero("Reingrese ID del actor: ");

        }

        break;
    default:
        printf("Opcion Invalida...\n");
        system("pause");

        break;
    }

}

/*void peliculas_ingresoPalabra(char buffer[],char mensaje[])
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
}*/

int peliculas_baja(ePelicula list[], eFecha listFecha[], int len, int flag)
{
    int id, r;

    if(flag!=0)
    {
        id=peliculas_ingresoNumero("Ingrese id: ");
        r=peliculas_remove(list, listFecha, len, id);
        flag=flag+r;
    }
    else
    {
        printf("No hay datos ingresados\n");
        system("pause");
    }

    return flag;
}

int peliculas_remove(ePelicula list[], eFecha listFecha[], int len, int id)
{
    int i, loEncontro;
    char respuesta;

    loEncontro=0;

    for(i=0; i<len; i++)
    {
        if(id == list[i].id&&list[i].isEmpty==FALSE)
        {
            printf("esta seguro de eliminar a %s de la lista?(s/n)", list[i].name);
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                list[i].isEmpty=TRUE;
                loEncontro = -1;
            }


            break;
        }

    }

    if(loEncontro==0)
    {
        printf("No se encontro ID\n");
        system("pause");

    }
    return loEncontro;
}
