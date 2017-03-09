//
//  funciones.h
//  Generador-RFC-CURP
//
//  Created by Gabriel gomez on 3/2/17.
//  Copyright © 2017 Gabriel gomez. All rights reserved.
//

#ifndef funciones_h
#define funciones_h

void eliminar_caracteres_especiales(char **cadena){
    char *cadena_sin_caracteres_especiales = (char*)malloc(50*sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(*cadena); i++) {
        if (ispunct((*cadena)[i])) {
        }else{
            cadena_sin_caracteres_especiales[j] = (*cadena)[i];
            j++;
        }
    }
    strcpy((*cadena), cadena_sin_caracteres_especiales);
}

void generar_codigo_clave_por_nombre(char **clave_por_nombre, char *apellido_paterno, char *apellido_materno, char *nombre){
    eliminar_caracteres_especiales(&apellido_paterno);
    eliminar_caracteres_especiales(&apellido_materno);
    eliminar_caracteres_especiales(&nombre);
    
    int longitudMinimaDeCadena = 1;
    
    //Tiene dos apellidos
    if (strlen(apellido_paterno) > longitudMinimaDeCadena && strlen(apellido_materno)> longitudMinimaDeCadena) {
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellido_paterno) == longitudMinimaDeCadena + 1) {
            (*clave_por_nombre)[0] = toupper(apellido_paterno[0]);
            (*clave_por_nombre)[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            (*clave_por_nombre)[0] = toupper(apellido_paterno[0]);
            (*clave_por_nombre)[1] = toupper(apellido_paterno[1]);
        }
        (*clave_por_nombre)[2] = toupper(apellido_materno[0]);
        (*clave_por_nombre)[3] = toupper(nombre[0]);
        (*clave_por_nombre)[4] = '\0';
        printf("Clave por nombre: %s\n", (*clave_por_nombre));
    }else if(strlen(apellido_paterno) == 1){
        //Tiene solo apellido materno
        
        //Si el apellido materno solo contiene un caracter.
        if (strlen(apellido_materno) == longitudMinimaDeCadena + 1) {
            (*clave_por_nombre)[0] = toupper(apellido_materno[0]);
            (*clave_por_nombre)[1] = 'X';
        }else{
            //Si el apellido materno contiene mas de un caracter.
            (*clave_por_nombre)[0] = toupper(apellido_materno[0]);
            (*clave_por_nombre)[1] = toupper(apellido_materno[1]);
        }
        (*clave_por_nombre)[2] = toupper(nombre[0]);
        (*clave_por_nombre)[3] = toupper(nombre[1]);
        (*clave_por_nombre)[4] = '\0';
        printf("Clave por nombre: %s\n", (*clave_por_nombre));
    }else{
        //Tienes solo apellido paterno
        
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellido_paterno) == longitudMinimaDeCadena + 1) {
            (*clave_por_nombre)[0] = toupper(apellido_paterno[0]);
            (*clave_por_nombre)[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            (*clave_por_nombre)[0] = toupper(apellido_paterno[0]);
            (*clave_por_nombre)[1] = toupper(apellido_paterno[1]);
        }
        (*clave_por_nombre)[2] = toupper(nombre[0]);
        (*clave_por_nombre)[3] = toupper(nombre[1]);
        (*clave_por_nombre)[4] = '\0';
        printf("Clave por nombre: %s\n", (*clave_por_nombre));
    }
}

void string_to_upper(char **cadena){
    for (int i = 0; i < strlen(*cadena); i++) {
        (*cadena)[i] = toupper((*cadena)[i]);
    }
}

int mes_a_numero(char *mes){
    int numero_de_mes = 0;
    string_to_upper(&mes);
    
    if (!strcmp(mes, "ENERO")) {
        numero_de_mes = 1;
    }else if (!strcmp(mes, "FEBRERO")) {
        numero_de_mes = 2;
    }else if (!strcmp(mes, "MARZO")) {
        numero_de_mes = 3;
    }else if (!strcmp(mes, "ABRIL")) {
        numero_de_mes = 4;
    }else if (!strcmp(mes, "MAYO")) {
        numero_de_mes = 5;
    }else if (!strcmp(mes, "JUNIO")) {
        numero_de_mes = 6;
    }else if (!strcmp(mes, "JULIO")) {
        numero_de_mes = 7;
    }else if (!strcmp(mes, "AGOSTO")) {
        numero_de_mes = 8;
    }else if (!strcmp(mes, "SEPTIEMBRE")) {
        numero_de_mes = 9;
    }else if (!strcmp(mes, "OCTUBRE")) {
        numero_de_mes = 10;
    }else if (!strcmp(mes, "NOVIEMBRE")) {
        numero_de_mes = 11;
    }else if (!strcmp(mes, "DICIEMBRE")) {
        numero_de_mes = 12;
    }else{
        printf("Mes no reconocido.\n");
    }
    
    return numero_de_mes;
}

void numero_a_cadena(int numero, char **cadena){
    if (numero < 10) {
        char num_temp[2];
        sprintf(num_temp, "%d", numero);
        sprintf(*cadena, "%d", 0);
        strcat(*cadena, num_temp);
    }else{
        sprintf(*cadena, "%d",numero);
    }
}

void generar_clave_por_fecha_nacimiento(char **clave_por_fecha, int anio, char *mes, int dia){
    int num_mes = 0, num_anio = 0;
    num_mes = mes_a_numero(mes);
    num_anio = anio % 100;
    
    char *numero_mes = (char*)malloc(3*sizeof(char));
    char *numero_anio = (char*)malloc(3*sizeof(char));
    char *numero_dia = (char*)malloc(3*sizeof(char));
    
    numero_a_cadena(num_anio, &numero_anio);
    numero_a_cadena(num_mes, &numero_mes);
    numero_a_cadena(dia, &numero_dia);
    
    strcat(*clave_por_fecha, numero_anio);
    strcat(*clave_por_fecha, numero_mes);
    strcat(*clave_por_fecha, numero_dia);
}

void generar_clave_homonimia(){
    
}


#endif /* funciones_h */
