#ifndef UTNVALIDACIONES_H_INCLUDED
#define UTNVALIDACIONES_H_INCLUDED

int utn_confirm();
int utn_isValidNombre(char *pBuffer, int limite);
int utn_isValidEnteroSoloNumeros(char *pBuffer, int limite);
//TOMA DE DATOS PARA EL MAIN
int utn_getAlfabetico(  char* pAlfabetico, int limite, char* mensaje,
                        char* mensajeError, int reintentos);
int utn_getNombre(  char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getAlfanumerico(char *pAlfanumerico, int limite, char *mensaje,
                        char *mensajeError, int reintentos);
int utn_getTexto(   char *pTexto, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getEnteroSoloNumeros(   int *pEntero, int limite, char *mensaje,
                                char *mensajeError, int reintentos);
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getFloatPositivo(   float *pFloat, int limite, char *mensaje,
                            char *mensajeError, int reintentos);
int utn_getMail(char *pMail, int limite, char *mensaje,
                char *mensajeError, int reintentos);
int utn_getTelefonoFijo(char *pTelefono, int limite, char *mensaje,
                        char *mensajeError, int reintentos);
int utn_getFecha(   char *pFecha, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getWeb( char *pWeb, int limite, char *mensaje,
                char *mensajeError, int reintentos);
int utn_getTarjeta( char *pTarjeta, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getCelularArgentino(char *pCelular, int limite, char *mensaje,
                            char *mensajeError, int reintentos);
int utn_getArchivo( char *pArchivo, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getArchivoPorTipo(  char *pArchivo, int limite, char *extension,
                            char *mensaje, char *mensajeError, int reintentos);
int utn_getCodigoPostal(char *pCodigoPostal, int limite, char *mensaje,
                        char *mensajeError, int reintentos);
int utn_getCuilOrCuit(  char *pDocumento, int limite, char *mensaje,
                        char *mensajeError, int reintentos);
int utn_coincideDigitoVerificador(  char *pDocumento, char *mensajeError);
int utn_getDni( char *pDocumento, int limite, char *mensaje,
                char *mensajeError, int reintentos);
int utn_getOpcionEntreDos(  char *pOpcion, int limite, char *pOpcionUno,  char *pOpcionDos,
                            char *pElegirOpcionUno, char *pElegirOpcionDos, int reintentos);
//ARRAYS
int utn_inicializarArrayEnteros(int* pArray, int limite, int valor);
void utn_mostrarArrayEnteros(int* pArray, int limite);
int utn_calcularMaximoArrayEnteros(int* pArray, int limite, int* pMaximo);
int utn_minimoDesdeEnArrayEnteros(int *pArray, int limite, int desde, int *pMinimo);
int utn_sortArrayEnterosPorBurbujeo(int *pArray, int limite, int orden);
int utn_sortArrayEnterosPorInsercion(int *pArray, int limite, int orden);
int utn_retornarMayor(int listado[], int tamanio);
int utn_retornarMenor(int listado[], int tamanio);
int utn_retornarCantidadDePares(int listado[], int tamanio);
int utn_retornarTotal(int listado[], int tamanio);
float utn_retornarPromedio(int listado[], int tamanio);
int utn_cantidadEnterosEnIntervalo(int listado[], int tamanio, int minimo, int maximo);





//MATH
float utn_sumarDosFlotantes(float numeroUno, float numeroDos);
float utn_restarDosFlotantes(float numeroUno, float numeroDos);
float utn_multiplicarDosFlotantes(float numeroUno, float numeroDos);
int utn_dividirDosFlotantes(float numeroUno, float numeroDos, float *resultadoDivision);
unsigned long long int utn_obternerResultadoFactorial(int numero);
int utn_realizarFactorialConFlotante(float numero, unsigned long long int *resultadoFactorial);

//OTHER
void utn_imprimirResultadoFloatOErrorEnPantalla(int opcionAMostrar,
                                                char mensajeResultado[],
                                                float resultado,
                                                char mensajeNoExiteResultado[],
                                                char mensajeError[]);
void utn_imprimirResultadoLongLongOErrorEnPantalla( int opcionAMostrar,
                                                    char mensajeResultado[],
                                                    unsigned long long int resultado,
                                                    char mensajeNoExiteResultado[],
                                                    char mensajeError[]);

#endif // UTNVALIDACIONES_H_INCLUDED
