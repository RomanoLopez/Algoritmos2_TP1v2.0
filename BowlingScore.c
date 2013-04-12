#include <stdio.h>
#include "TDA_Parser.h"
#include "TDA_Parser.c"
#include "TDA_Score.c"
#include "TDA_Score.h"

int main(int argc, char *argv[]){

	char Jugador[20], Separador, *Archivo;
  	int ErrorScore[20], Puntaje, J;
  	TDA_Parser Parser, *PParser;
	TDA_Score Score, *PScore;

  	Separador = '|';
  	PParser = &Parser;
  	PScore = &Score;
  	Archivo = argv[0];
	
	if (parserCrear(PParser, Archivo, Separador))
	  	While (obtenerSiguienteLinea(PParser))
			if (s_crear(PScore)){
	        	s_establecerParticipante(PScore,PParser->Campo00);
	        	for(J=1; J < 11; ++J){
	          		switch (J){
	            	case 1: s_AgregarTiro(PScore,PParser->Campo01,J); break;
	            	case 2: s_AgregarTiro(PScore,PParser->Campo02,J); break;
	            	case 3: s_AgregarTiro(PScore,PParser->Campo03,J); break;
	            	case 4: s_AgregarTiro(PScore,PParser->Campo04,J); break;
	            	case 5: s_AgregarTiro(PScore,PParser->Campo05,J); break;
	            	case 6: s_AgregarTiro(PScore,PParser->Campo06,J); break;
	            	case 7: s_AgregarTiro(PScore,PParser->Campo07,J); break;
	            	case 8: s_AgregarTiro(PScore,PParser->Campo08,J); break;
                    case 9: s_AgregarTiro(PScore,PParser->Campo09,J); break;
                    case 10: s_AgregarTiro(PScore,PParser->Campo10,J); break;
                    }
                }
                Puntaje = s_calcularResultado(Score);
                printf("%s, %d",s_obtenerParticipante(Score, Jugador), Puntaje);
            }
            else
                printf("Error en la creacion del Score");

    else{
		printf("Error en la carga del Parser");
        return 0;
	}
    system("Pause");
    return 1;
}
