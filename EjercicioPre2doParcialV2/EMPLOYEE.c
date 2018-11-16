#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EMPLOYEE.h"
#include "LinkedList.h"
#include "Parser.h"
#include "UtnValidaciones.h"

static int isValidId(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
 * \brief    Evalua si es un nombre valido
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el tamano maximo del string
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidNombre(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidNombre(pBuffer,limite);
    if(retorno != 1)
    {
        printf("\nEl nombre debe comenzar por mayuscula y el resto minusculas");
    }
    return retorno;
}
/**
 * \brief Evalua si se trata de una cantidad de horas trabajada valida
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidHorasTrabajadas(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
 * \brief Evalua si se trata de un sueldo valido
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidSueldo(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
 * \brief Incrementa el nuevo Id del empleado en 1, empezando desde 0 con el metodo static.
 *
 * \return Int Devuelve el nuevo Id.
 */
int employee_getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
/**
 * \brief Toma el indice de un empleado por el Id.
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se buscan los empleados.
 * \param index int* Se retorna por parametros el index donde se encuentra el empleado.
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getById(LinkedList* pArrayListEmployee, int* index)
{
    int retorno = -1;
    int id;
    if(pArrayListEmployee != NULL)
    {
        employee_list(pArrayListEmployee);
        if( !utn_getEntero(&id, 10, "\nIntroduzca el Id: ", "", 0) &&
            !employee_getIndexById(pArrayListEmployee, id, index))
        {
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Toma el indice de un empleado por el Id recorriendo todo el LinkedList
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se buscan los empleados.
 * \param index int* Se retorna por parametros el index donde se encuentra el empleado.
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getIndexById(LinkedList* pArrayListEmployee,int id, int* index)
{
    int retorno = -1;
    Employee* pEmpleado;
    int bufferId;
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            if(bufferId == id)
            {
                *index = ll_indexOf(pArrayListEmployee, pEmpleado);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Setter del Id
 *
 * \param this Employee* Es el empleado donde se guarda el id
 * \param id int Es el id que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter del Id
 *
 * \param this Employee* Es el empleado que contiene el id
 * \param id int* Se retorna por parametros el dato del id
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter del Nombre
 *
 * \param this Employee* Es el empleado donde se guarda el nombre
 * \param nombre char* Es el nombre que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter del Nombre
 *
 * \param this Employee* Es el empleado que contiene el nombre
 * \param nombre char* Se retorna por parametros el dato del nombre
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter de las horas
 *
 * \param this Employee* Es el empleado donde se guardan las horas trabajadas
 * \param horasTrabajadas int Es la cantidad de horas que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter de las horasTrabajadas
 *
 * \param this Employee* Es el empleado que contiene las horasTrabajadas
 * \param id int* Se retorna por parametros el dato de las horasTrabajadas
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter del Sueldo
 *
 * \param this Employee* Es el empleado donde se guarda el sueldo
 * \param sueldo int Es el sueldo que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Getter del Sueldo
 *
 * \param this Employee* Es el empleado que contiene el sueldo
 * \param sueldo int* Se retorna por parametros el dato del sueldo
 * \return En caso de exito retorna 1, si no 0
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Setter de todos las propiedades del empleado
 *
 * \param this Employee* Es el empleado donde se guardan estos datos
 * \param id int Es el id que se guarda en el empleado
 * \param nombre char* Es el nombre que se guarda en el empleado
 * \param horasTrabajadas int Son las horas trabajadas a guardar en el empleado
 * \param sueldo int Es el sueldo que se guarda en el empleado
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_setAll(Employee* this, int id,char* nombre, int horasTrabajadas, int sueldo)
{
    int retorno = -1;
    if( !employee_setNombre(this, nombre) &&
        !employee_setHorasTrabajadas(this, horasTrabajadas)&&
        !employee_setSueldo(this, sueldo))
    {
        retorno = 0;
    }
    return retorno;

}
/**
 * \brief Muestra toda la informacion de un solo empleado
 *
 * \param this Employee* Es el empleado que contiene la informacion
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_showInfo(Employee* this)
{
    int retorno = -1;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(this!=NULL)
    {
        employee_getId(this, &bufferId);
        employee_getNombre(this, bufferNombre);
        employee_getHorasTrabajadas(this, &bufferHorasTrabajadas);
        employee_getSueldo(this, &bufferSueldo);
        printf( "\nId: %d - Nombre: %s - Horas: %d - Sueldo: %d",
                bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Asigna el espacio de memoria para la creacion de un empleado
 * \return Employee* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Employee* employee_new()
{
    Employee* this;
    this = malloc(sizeof(Employee));
    return this;
}
/**
 * \brief Libera el espacio de memoria donde se encontraba el empleado utilizando free()
 *
 * \param this Employee* Es el empleado que se desea eliminar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Asigna el espacio de memoria para la creacion de un empleado con todos sus atributos cargados
 * \return Employee* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Employee* employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString)
{
    Employee* this;
    this = employee_new();
    Employee* retorno = NULL;
    int idInt = atoi(idString);
    int horasTrabajadasInt = atoi(horasTrabajadasString);
    int sueldoInt = atoi(sueldoString);
    if( isValidId(idString,20) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,20) &&
        isValidSueldo(sueldoString,20) &&
        !employee_setAll(this, idInt, nombre, horasTrabajadasInt, sueldoInt))
    {
        retorno = this;
    }
    else
    {
        employee_delete(this);
    }
    return retorno;
}
/**
 * \brief Aniade un empleado al final de la LinkedList
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_add(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    char bufferIdString[20];
    int bufferIdInt;
    char bufferNombre[128];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    if( pArrayListEmployee != NULL &&
        !utn_getTexto(  bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0) &&
        !utn_getTexto(  bufferHorasTrabajadas,20,"\nIntroduzca horas trabajadas del empleado: ", "",0) &&
        !utn_getTexto(  bufferSueldo,20,"\nIntroduzca sueldo del empleado: ","",0))
    {
        bufferIdInt = employee_getNextId();
        snprintf(bufferIdString, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleado = employee_newConParametros(  bufferIdString,bufferNombre, 128,
                                                bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleado != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Edita un empleado seleccionado de la LinkedList a traves de un id
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_edit(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int indexEmpleado;
    if( pArrayListEmployee != NULL &&
        !employee_getById(pArrayListEmployee,&indexEmpleado))
    {
        pEmpleado = ll_get(pArrayListEmployee, indexEmpleado);
        if( !employee_confirmEditOrRemove(pEmpleado))
        {
            retorno = employee_menuEdicion(pEmpleado);
        }
    }
    return retorno;
}
/**
 * \brief Se selecciona que atributos se desean editar del empleado
 *
 * \param this Employee* Es el empleado que se desea editar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_menuEdicion(Employee* this)
{
    int retorno = -1;
    Employee* pEmpleadoAux;
    char previousNombre[128];
    int previousHorasTrabajadas;
    int previousSueldo;
    char bufferNombre[128];
    char bufferId[20];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    int bufferIdInt;
    int bufferHorasTrabajadasInt;
    int bufferSueldoInt;
    if(this != NULL)
    {
        employee_getNombre(this, previousNombre);
        printf("\nEditar Nombre: %s", previousNombre);
        if(!utn_confirm())
        {
            utn_getTexto(bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0);
        }
        else
        {
            employee_getNombre(this, bufferNombre);
        }

        employee_getHorasTrabajadas(this, &previousHorasTrabajadas);
        printf("\nEditar Horas: %d", previousHorasTrabajadas);
        if(!utn_confirm())
        {
            utn_getTexto(bufferHorasTrabajadas,128,"\nIntroduzca horas del empleado: ","",0);
        }
        else
        {
            employee_getHorasTrabajadas(this, &bufferHorasTrabajadasInt);
            snprintf(bufferHorasTrabajadas, 20*sizeof(char), "%d", bufferHorasTrabajadasInt);
        }

        employee_getSueldo(this, &previousSueldo);
        printf("\nEditar Sueldo: %d",previousSueldo);
        if(!utn_confirm())
        {
            utn_getTexto(bufferSueldo,128,"\nIntroduzca sueldo del empleado: ","",0);
        }
        else
        {
            employee_getSueldo(this, &bufferSueldoInt);
            snprintf(bufferSueldo, 20*sizeof(char), "%d", bufferSueldoInt);
        }
        employee_getId(this, &bufferIdInt);
        snprintf(bufferId, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleadoAux = employee_newConParametros(   bufferId, bufferNombre, 128,
                                                    bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleadoAux != NULL)
        {
            printf("\nEmpleado sin editar");
            employee_showInfo(this);
            printf("\nEmpleado editado");
            employee_showInfo(pEmpleadoAux);
            if(!utn_confirm())
            {
                employee_setAll(this, bufferIdInt, bufferNombre,
                                atoi(bufferHorasTrabajadas), atoi(bufferSueldo));
                retorno = 0;
            }
        }
    }
    return retorno;
}
/**
 * \brief Elimina un empleado seleccionado de la LinkedList a traves de un id
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_remove(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int indexRemove;
    if( pArrayListEmployee != NULL &&
        !employee_getById(pArrayListEmployee,&indexRemove))
    {
        pEmpleado = ll_get(pArrayListEmployee, indexRemove);
        if( !employee_confirmEditOrRemove(pEmpleado))
        {
            free(ll_pop(pArrayListEmployee, indexRemove));
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Muestra el empleado seleccionado y confirma si se desea editar o eliminar
 *
 * \param this Employee* Es el empleado que se desea editar o eliminar
* \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_confirmEditOrRemove(Employee* this)
{
    int retorno = -1;
    system("clear");
    printf("\nHa seleccionado el siguiente empleado");
    employee_showInfo(this);
    if( !utn_confirm())
    {
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Muestra toda la informacion de los empleados
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_list(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int numeroEmpleados = 0;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_showInfo(pEmpleado);
            numeroEmpleados++;
        }
        printf("\nHay %d empleados\n",numeroEmpleados);
    }
    return retorno;
}
/**
 * \brief Ordena todos los empleados por el criterio seleccionado a traves de un menu
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int employee_sort(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option = 0;
    if(pArrayListEmployee != NULL)
    {
        printf( "\n1. Id(Menor a Mayor)"
                "\n2. Id(Mayor a Menor)"
                "\n3. Nombre(A-Z)"
                "\n4. Nombre(Z-A)"
                "\n5. Horas(Menor a Mayor)"
                "\n6. Horas(Mayor a Menor)"
                "\n7. Sueldo(Menor a Mayor)"
                "\n8. Sueldo(Mayor a Menor)"
                "\n9. Cancelar");
        utn_getEntero(&option, 5, "Seleccione...\n", "", 0);
        if(option > 0 && option < 9)
        {
            printf("Esto puede llevar unos minutos...\n");
        }
        switch(option)
        {
            case 1:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortId,1))
                {
                    retorno = 0;
                }
                break;
            case 2:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortId,0))
                {
                    retorno = 0;
                }
                break;
            case 3:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortNombre,1))
                {
                    retorno = 0;
                }
                break;
            case 4:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortNombre,0))
                {
                    retorno = 0;
                }
                break;
            case 5:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortHorasTrabajadas,1))
                {
                    retorno = 0;
                }
                break;
            case 6:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortHorasTrabajadas,0))
                {
                    retorno = 0;
                }
                break;
            case 7:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortSueldo,1))
                {
                    retorno = 0;
                }
                break;
            case 8:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortSueldo,0))
                {
                    retorno = 0;
                }
                break;
            default:
                break;
        }
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus id
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int employee_criterioSortId(void* thisA, void* thisB)
{
    int idA;
    int idB;
    int retorno = 0;
    employee_getId(thisA,&idA);
    employee_getId(thisB,&idB);
    if(idA > idB)
    {
        retorno = 1;
    }
    else if(idB > idA)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus nombres
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int employee_criterioSortNombre(void* thisA, void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int retorno = 0;
    employee_getNombre(thisA,nombreA);
    employee_getNombre(thisB,nombreB);
    if(strcmp(nombreA,nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus horas
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int employee_criterioSortHorasTrabajadas(void* thisA, void* thisB)
{
    int horasTrabajadasA;
    int horasTrabajadasB;
    int retorno = 0;
    employee_getHorasTrabajadas(thisA,&horasTrabajadasA);
    employee_getHorasTrabajadas(thisB,&horasTrabajadasB);
    if(horasTrabajadasA > horasTrabajadasB)
    {
        retorno = 1;
    }
    else if(horasTrabajadasB > horasTrabajadasA)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus sueldos
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int employee_criterioSortSueldo(void* thisA, void* thisB)
{
    int sueldoA;
    int sueldoB;
    int retorno = 0;
    employee_getSueldo(thisA,&sueldoA);
    employee_getSueldo(thisB,&sueldoB);
    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoB > sueldoA)
    {
        retorno = -1;
    }
    return retorno;
}



void em_calcularSueldo(void* p)
{

}
