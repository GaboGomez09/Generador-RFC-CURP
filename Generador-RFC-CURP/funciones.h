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

void generar_codigo_clave_por_nombre(char **curp, char *apellido_paterno, char *apellido_materno, char *nombre){
    eliminar_caracteres_especiales(&apellido_paterno);
    eliminar_caracteres_especiales(&apellido_materno);
    eliminar_caracteres_especiales(&nombre);
    
    int longitudMinimaDeCadena = 1;
    
    //Tiene dos apellidos
    if (strlen(apellido_paterno) > longitudMinimaDeCadena && strlen(apellido_materno)> longitudMinimaDeCadena) {
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellido_paterno) == longitudMinimaDeCadena + 1) {
            (*curp)[0] = toupper(apellido_paterno[0]);
            (*curp)[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            (*curp)[0] = toupper(apellido_paterno[0]);
            (*curp)[1] = toupper(apellido_paterno[1]);
        }
        (*curp)[2] = toupper(apellido_materno[0]);
        (*curp)[3] = toupper(nombre[0]);
        (*curp)[4] = '\0';
        printf("Clave por nombre: %s\n", (*curp));
    }else if(strlen(apellido_paterno) == 1){
        //Tiene solo apellido materno
        
        //Si el apellido materno solo contiene un caracter.
        if (strlen(apellido_materno) == longitudMinimaDeCadena + 1) {
            (*curp)[0] = toupper(apellido_materno[0]);
            (*curp)[1] = 'X';
        }else{
            //Si el apellido materno contiene mas de un caracter.
            (*curp)[0] = toupper(apellido_materno[0]);
            (*curp)[1] = toupper(apellido_materno[1]);
        }
        (*curp)[2] = toupper(nombre[0]);
        (*curp)[3] = toupper(nombre[1]);
        (*curp)[4] = '\0';
        printf("Clave por nombre: %s\n", (*curp));
    }else{
        //Tienes solo apellido paterno
        
        //Si el apellido paterno solo contiene un caracter.
        if (strlen(apellido_paterno) == longitudMinimaDeCadena + 1) {
            (*curp)[0] = toupper(apellido_paterno[0]);
            (*curp)[1] = 'X';
        }else{
            //Si el apellido paterno contiene mas de un caracter.
            (*curp)[0] = toupper(apellido_paterno[0]);
            (*curp)[1] = toupper(apellido_paterno[1]);
        }
        (*curp)[2] = toupper(nombre[0]);
        (*curp)[3] = toupper(nombre[1]);
        (*curp)[4] = '\0';
        printf("Clave por nombre: %s\n", (*curp));
    }
}




#endif /* funciones_h */
