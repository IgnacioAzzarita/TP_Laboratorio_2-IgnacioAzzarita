#include "ArrayEmployee.h"
 #include <stdio.h>
#include <stdlib.h>
int initEmployees(Employee lista[] ,int len)
{
    int i;
    if(len > 0 && len <= 1000){
    for(i=0;i<len;i++)
    {
        Employee empleado={0,"","",0.0,0,1};
        lista[i]=empleado;
    }
    return 0;
    }
    return -1;
}
int addEmployee(Employee arrayEmployee[] ,int len,int id,char name[],char lastName[],float salary,int sector)
{
    int i;
    int nextId;
    for(i=0;i<len;i++)
    {
        nextId=arrayEmployee[i].id++;
        if(arrayEmployee[i].isEmpty==1)
        {
            arrayEmployee[i].id=nextId;
            strcpy(arrayEmployee[i].name,name);
            strcpy(arrayEmployee[i].lastName,lastName);
            arrayEmployee[i].salary=salary;
            arrayEmployee[i].sector=sector;
            arrayEmployee[i].isEmpty=0;
            return 0;
        }
    }
    return -1;
}
int printEmployess(Employee arrayEmployee[],int len)
{

    if(len>0 && len <=1000)
    {
         printf("  ID                Nombre             Apellido          Salario     Sector \n");
         for(int i = 0; i < len; i++)
        {
            if(arrayEmployee[i].isEmpty != 1)
            {
             showEmployee(arrayEmployee[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}
int findEmployeebyId(Employee lista[],int len, int id)
{
    int indexId = -1;
    if(len > 0 && len <= 1000)
    {
    for(int i = 0; i < len; i++)
    {
      if(lista[i].id == id && lista[i].isEmpty == 0)
        {
                indexId = i;
                break;
        }
    }
}
    return indexId;
}
int sortEmployees(Employee lista[], int len, int order)
{
    if(len < 0 || len > 1000 || order < 0 || order > 1 )
    {
        return -1;
    }

    Employee aux;
    if(order == 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(lista[i].sector > lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if (lista[i].sector == lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName) > 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
    else if(order == 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(lista[i].sector < lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if (lista[i].sector == lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName) < 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }

    return 0;
}

int removeEmployee(Employee* list, int len)
{
    int error = -1;
    int id;
    int index;
    char confirmation;
    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(len > 0 && len <= 1000)
    {

        printf("\nIngrese ID del empleado a eliminar: ");
        scanf("%d", &id);
        index = findEmployeebyId(list,len, id);
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {

            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                list[index].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}
void showEmployee(Employee emp)
{

    printf("%5d %20s %20s          %7.2f    %4d\n",
           emp.id,
           emp.name,
           emp.lastName,
           emp.salary,
           emp.sector);

}
