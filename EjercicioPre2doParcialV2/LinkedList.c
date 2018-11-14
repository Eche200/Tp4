#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stdarg
#include "LinkedList.h"
static Node* nodoGlobal;

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this) && ll_len(this) > 0)
    {
        pNode= this->pFirstNode;
        for(i=0 ; i < nodeIndex;i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{


    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode = malloc(sizeof(Node));
    Node* auxNodeAnterior = NULL;
    Node* auxNodeSiguiente = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(nodeIndex == 0)
        {
            pNewNode->pNextNode = this->pFirstNode;
            this->pFirstNode = pNewNode;
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this))
        {
            auxNodeAnterior = getNode(this, nodeIndex-1);
            auxNodeSiguiente = getNode(this, nodeIndex);
            auxNodeAnterior->pNextNode = pNewNode;
            pNewNode->pNextNode = auxNodeSiguiente;
        }
        this->size += 1;
        pNewNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        //this->size++;
        addNode(this, ll_len(this), pElement);

        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;
    if(this !=NULL && index >=0 && index < ll_len(this))
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    if(this !=NULL && index >=0 && index < ll_len(this))
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* siguienteNodo = NULL;
    Node* anteriorNodo= NULL;
    if(this != NULL && index >= 0 &&  index < ll_len(this))
    {
        auxNode=getNode(this,index);
        if(index == 0)
        {
            this->pFirstNode = auxNode->pNextNode;
            free(auxNode);
        }else{
        anteriorNodo = getNode(this,index-1);
        siguienteNodo = getNode(this,index+1);
        anteriorNodo->pNextNode= siguienteNodo;
        free(auxNode);
        }
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i=0;
    //Node* auxNode = NULL;
    if(this !=NULL)
    {
        for(i = 0 ; i < ll_len(this) ; i++)
        {
            ll_remove(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxNode;
    if(this != NULL )
    {
        for( i= 0; i< ll_len(this); i++)
        {
            auxNode = getNode(this,i);
            if(auxNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
        else if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >=0 && index < ll_len(this))
    {
        returnAux = ll_get(this , index);
        ll_remove(this , index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    int i;
    if(this != NULL )
    {
        returnAux = 0;
        for( i = 0; i < ll_len(this) ; i++)
        {
            auxNode = getNode(this , i);
            if( auxNode->pElement == pElement)
            {
                returnAux= 1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i = 0;
    int j = 0;
    Node* auxNodeLista2 = NULL;
    if(this != NULL  && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0 ; i < ll_len(this) ; i++)
        {
            auxNodeLista2 = getNode(this2,j);
            if(!ll_contains(this,auxNodeLista2->pElement))
            {
                returnAux = 0;
                break;
            }
            j++;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNodo = NULL;
    int i;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > 0 && to >from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i = from ; i <= to ; i++)
        {
            auxNodo = ll_get(this,i);
            ll_add(cloneArray,auxNodo);
        }
    }
    return cloneArray;
}




/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* auxNodo = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i = 0 ; i < ll_len(this); i++)
        {
            auxNodo = ll_get(this,i);
            ll_add(cloneArray,auxNodo);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int size=ll_len(this);
    int flagSwap;
    void* thisElementoUno;
    void* thisElementoDos;
    int retOrderValue;
    if(this != NULL &&size > 0 && pFunc != NULL && (order == 1 || order == 0))
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<size;i++)
            {
                thisElementoUno =ll_get(this,i);
                thisElementoDos = ll_get(this,i+1);
                if(thisElementoUno != NULL && thisElementoDos != NULL)
                {
                    retOrderValue = pFunc(thisElementoUno , thisElementoDos);
                    if((order == 0 &&retOrderValue == -1) || (retOrderValue == 1 && order == 1))
                    {   //Orden ascendente
                        flagSwap = 1;
                        ll_set(this,i,thisElementoDos);
                        ll_set(this,i+1,thisElementoUno);
                    }
                }
            }
        }while(flagSwap == 1);
        returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_filter (LinkedList* this , int(*pFunction)(void* pElemento))
{
    LinkedList* nuevaLinkedList = NULL;
    ll_startIter(this);

    if(this != NULL && pFunction !=NULL)
    {
        do
        {
            if(!pFunction(nodoGlobal->pElement))
            {
                ll_add(nuevaLinkedList , ll_getNext());
            }

        }while(ll_getNext() != NULL);
    }
    return nuevaLinkedList;
}



int FuncionMap (LinkedList* this , int(*pFunction)(void* pElemento))
{
    int retorno = 0;
    void* pElemento = NULL;
    int resultadoDeLaFuncionAgregar;
    if(this != NULL && pFunction != NULL )
    {
        ll_startIter(this);
        do
        {
            pElemento = ll_getNext();
            resultadoDeLaFuncionAgregar = pFunction(pElemento);
            if(! resultadoDeLaFuncionAgregar)
            {
                retorno = 1;
                break;
            }
        }while(nodoGlobal->pElement != NULL);
    }
    return retorno;

}





void ll_startIter( LinkedList* this)
{
    if(this != NULL)
    {
        nodoGlobal = this->pFirstNode;
    }
}

void* ll_getNext()
{
    void* pElemento = nodoGlobal->pElement;
    nodoGlobal= nodoGlobal->pNextNode;
    return pElemento;
}


/*
void prueba (LinkedList* this)
{
    FuncionMap(this,ll_add(this,))

}*/





