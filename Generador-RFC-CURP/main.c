//
//  main.c
//  Generador-RFC-CURP
//
//  Created by Gabriel gomez on 3/2/17.
//  Copyright © 2017 Gabriel gomez. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"

char* eliminarCaracteresEspeciales(char *cadena){
    char *cadenaSinCaracteresEspeciales = (char*)malloc(50*sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(cadena); i++) {
        if (ispunct(cadena[i])) {
        }else{
            cadenaSinCaracteresEspeciales[j] = cadena[i];
            j++;
        }
    }
    return cadenaSinCaracteresEspeciales;
}

char* removerTilde( char* str ) {
    //char *p = (char*)malloc(50*sizeof(char));
    for (int i = 0; i < strlen(str); i++) {
        if ((int)str[i] == 131 || (int)str[i] == 132 || (int)str[i] == 133 || (int)str[i] == 134) {
            
        }
    }
    return str;
}

int main(int argc, const char * argv[]) {
    char *nombre = (char*)malloc(50*sizeof(char));
    char *apellido_paterno = (char*)malloc(50*sizeof(char));
    char *apellido_materno = (char*)malloc(50*sizeof(char));
    char *curp = (char*)malloc(10*sizeof(char));
    //char alfabetoLatinoEstandar[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    //Esto es porque aunque se omita alguna entrada el 'enter' se registra como un caracter.
    
    printf("Apellido Paterno : ");
    fgets(apellido_paterno,50,stdin);
    
    printf("Apellido Materno : ");
    fgets(apellido_materno,50,stdin);
    
    printf("Nombre : ");
    fgets(nombre,50,stdin);
    
    generar_codigo_clave_por_nombre(&curp, apellido_paterno, apellido_materno, nombre);
    
    
    
    return 0;
}
