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
    char nombre[50], apellidoP[50], apellidoM[50], clavePorNombre[5];
    //char alfabetoLatinoEstandar[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    //Esto es porque aunque se omita alguna entrada el 'enter' se registra como un caracter.
    int longitudMinimaDeCadena = 1;
    
    printf("Apellido Paterno : ");
    fgets(apellidoP,50,stdin);
    memcpy(apellidoP, eliminarCaracteresEspeciales(apellidoP), strlen(apellidoP)+1);
    //memcpy(apellidoP, removerTilde(apellidoP), strlen(apellidoP+1));
    
    printf("Apellido Materno : ");
    fgets(apellidoM,50,stdin);
    memcpy(apellidoM, eliminarCaracteresEspeciales(apellidoM), strlen(apellidoM)+1);
    //memcpy(apellidoM, removerTilde(apellidoM), strlen(apellidoM+1));
    
    printf("Nombre : ");
    fgets(nombre,50,stdin);
    memcpy(nombre, eliminarCaracteresEspeciales(nombre), strlen(nombre)+1);
    //memcpy(nombre, removerTilde(nombre), strlen(nombre+1));
    
    //Tiene dos apellidos
    if (strlen(apellidoP) > longitudMinimaDeCadena && strlen(apellidoM)> longitudMinimaDeCadena) {
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellidoP) == longitudMinimaDeCadena + 1) {
            clavePorNombre[0] = toupper(apellidoP[0]);
            clavePorNombre[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            clavePorNombre[0] = toupper(apellidoP[0]);
            clavePorNombre[1] = toupper(apellidoP[1]);
        }
        clavePorNombre[2] = toupper(apellidoM[0]);
        clavePorNombre[3] = toupper(nombre[0]);
        clavePorNombre[4] = '\0';
        printf("Clave por nombre: %s\n", clavePorNombre);
    }else if(strlen(apellidoP) == 1){
        //Tiene solo apellido materno
        
        //Si el apellido materno solo contiene un caracter.
        if (strlen(apellidoM) == longitudMinimaDeCadena + 1) {
            clavePorNombre[0] = toupper(apellidoM[0]);
            clavePorNombre[1] = 'X';
        }else{
            //Si el apellido materno contiene mas de un caracter.
            clavePorNombre[0] = toupper(apellidoM[0]);
            clavePorNombre[1] = toupper(apellidoM[1]);
        }
        clavePorNombre[2] = toupper(nombre[0]);
        clavePorNombre[3] = toupper(nombre[1]);
        clavePorNombre[4] = '\0';
        printf("Clave por nombre: %s\n", clavePorNombre);
    }else{
        //Tienes solo apellido paterno
        
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellidoP) == longitudMinimaDeCadena + 1) {
            clavePorNombre[0] = toupper(apellidoP[0]);
            clavePorNombre[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            clavePorNombre[0] = toupper(apellidoP[0]);
            clavePorNombre[1] = toupper(apellidoP[1]);
        }
        clavePorNombre[2] = toupper(nombre[0]);
        clavePorNombre[3] = toupper(nombre[1]);
        clavePorNombre[4] = '\0';
        printf("Clave por nombre: %s\n", clavePorNombre);
    }
    
    return 0;
}
