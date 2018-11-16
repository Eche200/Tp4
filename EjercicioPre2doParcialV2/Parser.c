#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EMPLOYEE.h"
#include "LinkedList.h"
#include "Parser.h"
#include "UtnValidaciones.h"
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    const char delimitante[2] = ",";
    FILE* pFileDos;
    FILE* pFile;
    char* bufferId;
    char* bufferNombre;
    char* bufferHoras;
    char auxFile[40000];

    pFile = fopen(fileName,"r");
    pFileDos = fopen("dataDos.csv","w");


    while( !feof(pFile) ) {

        fgets(auxFile,40000,pFile);
        bufferNombre = strtok(auxFile,delimitante);
        bufferHoras = strtok(NULL, delimitante);
        bufferId = strtok(NULL , "\n");


        fprintf(pFileDos,bufferNombre);
        fprintf(pFileDos,",");
        fprintf(pFileDos,bufferHoras);
        fprintf(pFileDos,",");
        fprintf(pFileDos,bufferId);
        fprintf(pFileDos,"\n");

        //printf( " %s", bufferNombre );
        //printf( " %s\n", bufferHoras );
    }


    fclose(pFile);
    fclose(pFileDos);


    return 1; // OK
}

