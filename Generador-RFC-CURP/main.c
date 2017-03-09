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
#include <math.h>
#include "funciones.h"

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
//    char *clave_por_nombre = (char*)malloc(10*sizeof(char));
//    char *clave_por_fecha = (char*)malloc(10*sizeof(char));
//    int anio = 0;
//    char *mes = (char*)malloc(15*sizeof(char));
//    int dia = 0;
    char *clave_homonimia = (char*)malloc(3);
    //char alfabetoLatinoEstandar[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    //Esto es porque aunque se omita alguna entrada el 'enter' se registra como un caracter.
    
    printf("Apellido Paterno : ");
    fgets(apellido_paterno,50,stdin);
    
    printf("Apellido Materno : ");
    fgets(apellido_materno,50,stdin);
    
    printf("Nombre : ");
    fgets(nombre,50,stdin);
    
//    printf("Anio en que nacio: ");
//    scanf("%d", &anio);
//    
//    printf("Mes en que nacio: ");
//    scanf("%s", mes);
//    
//    printf("Dia en que nacio: ");
//    scanf("%d", &dia);
    
//    generar_codigo_clave_por_nombre(&clave_por_nombre, apellido_paterno, apellido_materno, nombre);
    
//    generar_clave_por_fecha_nacimiento(&clave_por_fecha, anio, mes, dia);
//    
//    printf("%s", clave_por_fecha);
    generar_clave_homonimia(&clave_homonimia, apellido_paterno, apellido_materno, nombre);
    return 0;
}
