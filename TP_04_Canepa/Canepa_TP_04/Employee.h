#include "ArrayList.h"

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p, int index);
Employee* newEmployee();
Employee* editEmployee(Employee *pEmpOriginal);
Employee* searchEmployee(ArrayList* pList,int *index,int auxId);
int compareEmployeeName(void* pEmployeeA,void* pEmployeeB);
int validateEmployee(Employee *pEmployee, char *input);
int importFile(ArrayList *pList, char *fName);
void createTxt(ArrayList *pList);
