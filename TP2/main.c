#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
#define OCUPADO 0
#define VACIO 1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;
int initEmployees(Employee lista[] ,int len);
int addEmployee(Employee lista[],int len,int id,char name[],char lastName[],float salary,int sector);
int printEmployess(Employee lista[],int len);
int findEmployeebyId(Employee lista[],int len,int id);
int sortEmployees(Employee lista[], int len, int order);
int main()
{
    Employee arrayEmployee[TAM];

    initEmployees(arrayEmployee,TAM);
    addEmployee(arrayEmployee,TAM,1,"Jose","Marmol",2564.8,2);
    findEmployeebyId(arrayEmployee,TAM,arrayEmployee.id);
    printEmployess(arrayEmployee,TAM);

    return 0;
}
int initEmployees(Employee lista[] ,int len)
{
    int i;
    if(len > 0 && len <= 1000){
    for(i=0;i<len;i++)
    {
        Employee empleado={0,"","",0.0,0,1};
        arrayEmployee[i]=empleado;
    }
    return 0;
    }
    return -1;
}
int addEmployee(Employee arrayEmployee,int len,int id,char name[],char lastName[],float salary,int sector)
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
int printEmployess(Employee lista[],int len)
{

    if(len>0 && len <=1000)
    {
        printf("ID Nombre  Apellido  Salario  Sector \n");
         for(int i = 0; i < len; i++)
        {
            if(arrayEmployee[i].isEmpty != 1)
            {
                printf(" %d %s %s %4.2f %d \n",
           arrayEmployee[i].id,
           arrayEmployee[i].name,
           arrayEmployee[i].lastName,
           arrayEmployee[i].salary,
           arrayEmployee[i].sector);
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
                if(lista[i].sector > lista[j].sector)  // Ordenar alfabeticamente por apellido && sector
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if (arrayEmployee[i].sector == arrayEmployee[j].sector && strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName) > 0)
                {
                    aux = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[j];
                    arrayEmployee[j] = aux;
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
                if(arrayEmployee[i].sector < arrayEmployee[j].sector)  // Ordenar en forma inversa alfabeticamente por apellido && sector
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if (arrayEmployee[i].sector == arrayEmployee[j].sector && strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName) < 0)
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


