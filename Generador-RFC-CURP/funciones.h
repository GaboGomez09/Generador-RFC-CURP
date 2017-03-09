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

void eliminar_espacios_blancos(char **cadena){
    char *cadena_sin_espacios_blancos = (char*)malloc(50*sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(*cadena); i++) {
        if (isspace((*cadena)[i])) {
        }else{
            cadena_sin_espacios_blancos[j] = (*cadena)[i];
            j++;
        }
    }
    strcpy((*cadena), cadena_sin_espacios_blancos);
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

int valor_de_caracter_cuadro1(char caracter){
    int valor_numerico = 0;
    
    switch (caracter) {
        case '0':
            valor_numerico = 0;
            break;
        case '1':
            valor_numerico = 1;
            break;
        case '2':
            valor_numerico = 2;
            break;
        case '3':
            valor_numerico = 3;
            break;
        case '4':
            valor_numerico = 4;
            break;
        case '5':
            valor_numerico = 5;
            break;
        case '6':
            valor_numerico = 6;
            break;
        case '7':
            valor_numerico = 7;
            break;
        case '8':
            valor_numerico = 8;
            break;
        case '9':
            valor_numerico = 9;
            break;
        case 'A':
            valor_numerico = 11;
            break;
        case 'B':
            valor_numerico = 12;
            break;
        case 'C':
            valor_numerico = 13;
            break;
        case 'D':
            valor_numerico = 14;
            break;
        case 'E':
            valor_numerico = 15;
            break;
        case 'F':
            valor_numerico = 16;
            break;
        case 'G':
            valor_numerico = 17;
            break;
        case 'H':
            valor_numerico = 18;
            break;
        case 'I':
            valor_numerico = 19;
            break;
        case 'J':
            valor_numerico = 21;
            break;
        case 'K':
            valor_numerico = 22;
            break;
        case 'L':
            valor_numerico = 23;
            break;
        case 'M':
            valor_numerico = 24;
            break;
        case 'N':
            valor_numerico = 25;
            break;
        case 'O':
            valor_numerico = 26;
            break;
        case 'P':
            valor_numerico = 27;
            break;
        case 'Q':
            valor_numerico = 28;
            break;
        case 'R':
            valor_numerico = 29;
            break;
        case 'S':
            valor_numerico = 32;
            break;
        case 'T':
            valor_numerico = 33;
            break;
        case 'U':
            valor_numerico = 34;
            break;
        case 'V':
            valor_numerico = 35;
            break;
        case 'W':
            valor_numerico = 36;
            break;
        case 'X':
            valor_numerico = 37;
            break;
        case 'Y':
            valor_numerico = 38;
            break;
        case 'Z':
            valor_numerico = 39;
        default:
            break;
    }
    
    return valor_numerico;
}

void generar_clave_homonimia(char **clave_homonimia, char *apellido_paterno, char *apellido_materno, char *nombre){
    char *nombre_completo = (char*)malloc(50*sizeof(char));
    eliminar_caracteres_especiales(&apellido_paterno);
    eliminar_caracteres_especiales(&apellido_materno);
    eliminar_caracteres_especiales(&nombre);
    string_to_upper(&apellido_paterno);
    string_to_upper(&apellido_materno);
    string_to_upper(&nombre);
    strcat(nombre_completo, nombre);
    strcat(nombre_completo, apellido_paterno);
    strcat(nombre_completo, apellido_materno);
    eliminar_espacios_blancos(&nombre_completo);

    int h = 0;
    
    for (int i = 0; i < strlen(nombre_completo) - 1; i++) {
        h += valor_de_caracter_cuadro1(nombre_completo[i])*valor_de_caracter_cuadro1(nombre_completo[i+1]);
    }
    
    h += pow(valor_de_caracter_cuadro1(nombre_completo[strlen(nombre_completo)-1]), 2);
    
    int cociente = (h%1000)/34;
    int residuo = (h%1000)%34;
    
    printf("%d %d", (h%1000)/34, (h%1000)%34);
}


#endif /* funciones_h */
