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
int printEmployess(Employee arrayEmployee[],int len);
int findEmployeebyId(Employee lista[],int len,int id);
int sortEmployees(Employee lista[], int len, int order);
