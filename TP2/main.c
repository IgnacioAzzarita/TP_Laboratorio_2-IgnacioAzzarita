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
int main()
{
    Employee arrayEmployee[TAM];
    return 0;
}
int initEmployees(Employee arrayEmployee[] ,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        Employee empleado={0,"","",0.0,0,1};
    }
    return arrayEmployee;
}
