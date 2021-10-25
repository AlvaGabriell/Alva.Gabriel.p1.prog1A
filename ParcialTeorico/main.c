#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOTE 10
typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    int precio;
}eNotebook;

float aplicarDescuento(int num1);
int contarCaracteres(char vector[], char letra);
void mostrarNote(eNotebook notebook);
int mostrarNotebooks(eNotebook notebook[],int tamN);
int ordenarPorMarca(eNotebook notebook[],int tamN);
int main()
{
    int indice;
    char nombre[50]="gabriel";
    int num=55;
    float resultado;
     eNotebook notebook[]=
    {
        {1000,"radeon","asno",100000},
        {1001,"intel","zoilo",150000},
        {1002,"amd","patito",70000},
        {1003,"athlon","quispe",55000},
        {1004,"ruedita","asno",102000},
        {1005,"pipo","zoilo",140000},
        {1006,"tanpe","patito",71000},
        {1007,"tesla","arnold",35000},
        {1008,"aston","patito",61000},
        {1009,"falcon","pentium",12000}
    };
    mostrarNotebooks(notebook,TAM_NOTE);
    ordenarPorMarca(notebook,TAM_NOTE);
    printf("\n\n");
    mostrarNotebooks(notebook,TAM_NOTE);
    printf("\n\n");

    resultado=aplicarDescuento(num);
    printf("%.2f\n",resultado);
    indice=contarCaracteres(nombre,'z');
    printf("%d\n",indice);
}

float aplicarDescuento(int num1)
{
    float resultado;
    resultado=(float)num1*5/100;
    return resultado;
}

int contarCaracteres(char vector[], char letra)
{
    int contador=0;
    if(vector!=NULL)
    {

        int indice;
        indice=strlen(vector);
        for(int i = 0; i<indice; i++)
        {
            if(vector[i]==letra)
            {
                contador++;
            }
        }
    }
    return contador;
}

void mostrarNote(eNotebook notebook)
{
    printf("%d    %10s      %10s        %d\n",
           notebook.id,
           notebook.procesador,
           notebook.marca,
           notebook.precio);

}
int mostrarNotebooks(eNotebook notebook[],int tamN)
{
    int todoOk=0;
    if(notebook!=NULL&&tamN>0)
    {
        for(int i= 0;i< tamN;i++)
        {
            mostrarNote(notebook[i]);
        }
    todoOk=1;
    }

    return todoOk;
}
int ordenarPorMarca(eNotebook notebook[],int tamN)
{
    eNotebook auxNote;
    int todoOk=0;
    if(notebook!=NULL&&tamN>0)
    {
        for(int i=0;i<tamN-1;i++)
        {
            for(int j=i+1;j<tamN;j++)
            {
                if(strcmp(notebook[i].marca,notebook[j].marca)>0||(strcmp(notebook[i].marca,notebook[j].marca)==0&&notebook[i].precio>notebook[j].precio))
                {
                    auxNote=notebook[i];
                    notebook[i]=notebook[j];
                    notebook[j]=auxNote;
                }

            }
        }
    }
    return todoOk;
}

