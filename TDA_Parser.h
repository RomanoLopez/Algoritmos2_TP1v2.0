# ifndef __TDA_Parser_h__
# define __TDA_Parser_h__
# define MAXCAR 20

typedef struct{
    char Campo00[MAXCAR];
    char Campo01[3];
    char Campo02[3];
    char Campo03[3];
    char Campo04[3];
    char Campo05[3];
    char Campo06[3];
    char Campo07[3];
    char Campo08[3];
    char Campo09[3];
    char Campo10[4];
    int NumLinea;
    FILE *Archivo;
    char Separador;
} TDA_Parser;

// Primitivas:

int parserCrear(TDA_Parser *Tda_Parser, char *Archivo, char Separador);

//PRECONDICIONES: ParserCrear recibe un TDA_PArser declarado, una ruta de archivo y un caracter separador.
// POSTCONDICIONES: Devuelve 1 si el archivo fue abierto y
// el el Parser pudo ser Inicalizado correctamente.


int obtenerSiguienteLinea(TDA_Parser *Tda_Parser);

//PRECONDICIONES: ObtenerSiguienteLinea recibe un parser Inicializado.
// POSTCONDICIONES: Devuelve 1 si el parser pudo ser cargado correctamente
// con los datos de una linea del archivo.


int obtenerCampo(TDA_Parser Tda_Parser, int N, char *Valor);

// PRECONDICIONES: ObtenerCampo Recibe un numero N entre 0 y 10 inclusive.
// 0 para el campo del Nombre y del 1 al 10 para los campos de las jugadas.
// POSTCONDICIONES: Devuelve 1 si se puedo realizar sin error, en caso contrario 0.


int Destruirlo(TDA_Parser *Tda_Parser);

// PRECONDICIONES: Destruir Recibe un Parcer que fue Inicializado y Usado correctamente.
// POSTCONDICION: Retorna 1 despues de cerrar el Archivo y liberado la memoria que usaba.

# endif
