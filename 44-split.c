#include "40-liste_stringhe.h"
#include <stdio.h>
#include <string.h>

lista split( char *);

void main(){
	char stringa_input[] = "   programmazione  in C o in  Python   con   laboratorio ";
	lista a = split( stringa_input );
	lista_print( a );
}

lista split( char *str ){
	lista a = lista_vuota();
	nodo  *ultimo;
	int lx = 0, rx = 0;
	char *str_temp = malloc( (strlen(str)+1)*sizeof(char));
	int finito = 0;
	
	while ( !finito ) {
		if ( str[lx] == ' '){ // scariamo gli spazi
			lx++;
			rx++;
		} else {
			if (str[lx] == '\0'){
				finito = 1;
			} else {
				if (str[rx] != ' ' && str[rx] != '\0')
					rx++;
				else { // inseriamo in a la parola tra lx e rx-1 
					strncpy(str_temp, str+lx, rx-lx);
					str_temp[rx-lx] = '\0';
					
					if ( a == NULL ){
						a = lista_in0(a, str_temp);
						ultimo = a;
					} else {
						ultimo = lista_in1(ultimo, str_temp);
						ultimo = ultimo->succ;
					}
					
					if( str[rx] == '\0' ){
						finito = 1;
					}
					
					rx++;
					lx = rx;
				}
			}
		}
	}
	
	free(str_temp);
	
	return a;
}
