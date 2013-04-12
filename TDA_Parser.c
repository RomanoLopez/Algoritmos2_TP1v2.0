#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TDA_Parser.h"


int parserCrear (TDA_Parser *Tda_Parser, char *Archivo, char Separador){
    FILE *P_Archivo;
    P_Archivo = fopen(Archivo,"r");
    if (P_Archivo){
        rewind(P_Archivo);
        if (eof(P_Archivo)){
            Tda_Parser->NumLinea = 0;
            Tda_Parser->Archivo = P_Archivo;
            Tda_Parser->Separador = Separador;
        }
        else
            return 0;
    }
    else
        return 0;
    return 1;
}


// Esta Funcion sera llamada por ObtenersiguienteLinea

int LeerCampo (char *Cadena, FILE *Arch, char Separa){
    char AUX, S;
    int J, FaltaLeer;

    S = Separa;
    FaltaLeer = 1;
    AUX = getc(Arch);
    while (!EOF){
        for(J = 0; FaltaLeer; J++){
            if ((AUX != '\n') && (AUX != S)){
                Cadena[J] = AUX;
                AUX = getc(Arch);
            }
            else{
                Cadena[J] = '\0';
                FaltaLeer = 0;
            }
        return 1;
        }
    return 0;
    }
}


// Esta Funcion sera lamada por ObtenersiguienteLinea

void CargarCampo (char *Cadena, int Campo, TDA_Parser *Tda_Parser){
    while (Campo < 11){
        switch (Campo){
            case 0:
                strcpy(Tda_Parser->Campo00, Cadena);
                break;
            case 1:
                strcpy(Tda_Parser->Campo01, Cadena);
                break;
            case 2:
                strcpy(Tda_Parser->Campo02, Cadena);
                break;
            case 3:
                strcpy(Tda_Parser->Campo03, Cadena);
                break;
            case 4:
                strcpy(Tda_Parser->Campo04, Cadena);
                break;
            case 5:
                strcpy(Tda_Parser->Campo05, Cadena);
                break;
            case 6:
                strcpy(Tda_Parser->Campo06, Cadena);
                break;
            case 7:
                strcpy(Tda_Parser->Campo07, Cadena);
                break;
            case 8:
                strcpy(Tda_Parser->Campo08, Cadena);
                break;
            case 9:
                strcpy(Tda_Parser->Campo09, Cadena);
                break;
            case 10:
                strcpy(Tda_Parser->Campo10, Cadena);
                break;
        }
    }
}


int obtenerSiguienteLinea (TDA_Parser *Tda_Parser){
    char Cadena[MAXCAR];
    int Campo;

    Campo = 0;

    while (Campo <= 10){
        if (LeerCampo(Cadena, Tda_Parser->Archivo, Tda_Parser->Separador)){
            CargarCampo(Cadena, Campo, Tda_Parser);
            ++Campo;
        }
        else
            break;
    }
    Tda_Parser->NumLinea += 1;
    if (Campo = 11)
        return 1;
    else
        return 0;
}


int obtenerCampo (TDA_Parser Tda_Parser, int N, char *Valor){
    if (0 <= N && N >= 10 && Valor && Tda_Parser.NumLinea){
        switch (N){
            case 0:
                strcpy(Valor, Tda_Parser.Campo00);
                break;
            case 1:
                strcpy(Valor, Tda_Parser.Campo01);
                break;
            case 2:
                strcpy(Valor, Tda_Parser.Campo02);
                break;
            case 3:
                strcpy(Valor, Tda_Parser.Campo03);
                break;
            case 4:
                strcpy(Valor, Tda_Parser.Campo04);
                break;
            case 5:
                strcpy(Valor, Tda_Parser.Campo05);
                break;
            case 6:
                strcpy(Valor, Tda_Parser.Campo06);
                break;
            case 7:
                strcpy(Valor, Tda_Parser.Campo07);
                break;
            case 8:
                strcpy(Valor, Tda_Parser.Campo08);
                break;
            case 9:
                strcpy(Valor, Tda_Parser.Campo09);
                break;
            case 10:
                strcpy(Valor, Tda_Parser.Campo10);
                break;
            }
        return 1;
    }
    else
        return 0;
}


int destruir (TDA_Parser *Tda_Parser){
    fclose(Tda_Parser->Archivo);
    return 1;
}
