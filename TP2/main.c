#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
#define OCUPADO 0
#define VACIO 1
#include "ArrayEmployee.h"
int main()
{
    Employee arrayEmployee[TAM];

    initEmployees(arrayEmployee,TAM);
    addEmployee(arrayEmployee,TAM,1,"Jose","Marmol",2564.8,2);
    findEmployeebyId(arrayEmployee,TAM,6);
    printEmployess(arrayEmployee,TAM);

    return 0;
}
