/*
TP3  �  2018
T�tulo: Esc�ner Flex
Grupo N� 03

Apellido y Nombre               E-mail                      	Legajo 
--------------------------------------------------------------------------
POMPEY PABLO SEBASTIAN          pompeypablo@hotmail.com     	157.181-3
YA�EZ AGUSTIN EMANUEL           agustin.y@outlook.com      	160.039-4
MONTI PABLO SEBASTIAN		pmonti@est.frba.utn.edu.ar  	158.826-6
MARI�O AUGUSTO                  augusto.8121@gmail.com      	159.754-1

*/
#include "scanner.h"
#include "parser.h"

int yylexerrs = 0;

int main(void)
{
	switch( (yyparse()) ){
	case 0:
		puts("Compilacion terminada con exito"); 
		printf("Errores sint�cticos: %d - Errores l�xicos: %d\n", yynerrs, yylexerrs);
		return 0;
	case 1:
		puts("Errores de compilacion"); 
		printf("Errores sint�cticos: %d - Errores l�xicos: %d\n", yynerrs, yylexerrs);
		return 1;
	case 2:
		puts("Memoria insuficiente"); 
		return 2;
	}

	return 0;
}

void yyerror(const char *msg){
	printf("l�nea #%d: %s\n", yylineno, msg);
	return;
}
