#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
int employee_getNextId();
int employee_getById(LinkedList* pArrayListEmployee, int* index);
int employee_getIndexById(LinkedList* pArrayListEmployee,int id, int* index);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setAll(Employee* this, int id,char* nombre, int horasTrabajadas, int sueldo);
int employee_showInfo(Employee* this);
Employee* employee_new();
int employee_delete(Employee* this);
Employee* employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString);
int employee_add(LinkedList* pArrayListEmployee);
int employee_edit(LinkedList* pArrayListEmployee);
int employee_menuEdicion(Employee* this);
int employee_remove(LinkedList* pArrayListEmployee);
int employee_confirmEditOrRemove(Employee* this);
int employee_list(LinkedList* pArrayListEmployee);
int employee_sort(LinkedList* pArrayListEmployee);
int employee_criterioSortId(void* thisA, void* thisB);
int employee_criterioSortNombre(void* thisA, void* thisB);
int employee_criterioSortHorasTrabajadas(void* thisA, void* thisB);
int employee_criterioSortSueldo(void* thisA, void* thisB);

void em_calcularSueldo(void* p);

#endif
