#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512


char lineas[1000][MAX_LINE_LENGTH];
char lineas2[1000][MAX_LINE_LENGTH];
char lineas3[1000][MAX_LINE_LENGTH];
char linea[MAX_LINE_LENGTH];
int indice = 0;
/*
char archivo[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/juntaFicheros/ciudades.txt";
char archivo2[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/juntaFicheros/callesViento.txt";
char archivo3[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/juntaFicheros/callesViento2.txt";
*/
char archivo4[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/juntaFicheros/cmake-build-debug/todosJuntos.txt";


//declaracion
void leerData1(char nombreArchivo[]);
void leerData2(char nombreArchivo[]);
void leerData3(char nombreArchivo[]);
void juntarArchivos(char nombreArchivo[]);
void comprobar(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    char *archivo = argv[1];
    char *archivo2 = argv[2];
    char *archivo3 = argv[3];
    comprobar(argc, argv);

    leerData1(archivo);
    //juntarArchivos(archivo4);
    //imprimirLineas();
    leerData2(archivo2);
    //juntarArchivos(archivo4);
    //imprimirLineas();
    leerData3(archivo3);
    juntarArchivos(archivo4);
    //imprimirLineas();
    //printf(lineas[1]);
    return 0;
}

void comprobar(int argc, char *argv[]){
    int i;

    // Itera sobre los argumentos
    for (i = 1; i < 4; i++) {
        // Verifica si el argumento actual está vacío
        if (argv[i] == '\0') {
            printf("hay args vacios, introduce todas los ficheros\n");
            exit(1);
        }
    }
    printf("No se encontraron argumentos vacios\n");
}

void leerData1(char nombreArchivo[]){
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    indice = 0;
    while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL) {
        strcpy(lineas[indice], linea);
        indice++;
    }


    fclose(archivo);

}

void leerData2(char nombreArchivo[]){
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    indice = 0;
    while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL) {
        strcpy(lineas2[indice], linea);
        indice++;
    }


    fclose(archivo);

}

void leerData3(char nombreArchivo[]){
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    indice = 0;
    while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL) {
        strcpy(lineas3[indice], linea);
        indice++;
    }


    fclose(archivo);

}

void imprimirLineas(){
    int i;
    for (i = 0; i < indice; i++) {
        printf("%s", lineas[i]);
    }

}
/*
void printLineas1(){
    for (int i = 0; i < indice; i++) {
        fprintf(archivo, lineas[i]);
        //printf(lineas[i]);
    }
}

void printLineas2(){
    for (int i = 0; i < indice; i++) {
        fprintf(archivo2, lineas2[i]);
        //printf(lineas[i]);
    }
}

void printLineas3(){
    for (int i = 0; i < indice; i++) {
        fprintf(archivo3, lineas3[i]);
        //printf(lineas[i]);
    }
}
*/

void juntarArchivos(char nombreArchivo[]){
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    for (int i = 0; i < 100; i++) {
        fprintf(archivo, lineas[i]);
        //printf(lineas[i]);
    }
    fprintf(archivo,"\n-------------------------------------\n");
    for (int i = 0; i < 100; i++) {
        fprintf(archivo, lineas2[i]);
        //printf(lineas[i]);
    }
    fprintf(archivo,"\n-------------------------------------\n");

    for (int i = 0; i < 100; i++) {
        fprintf(archivo, lineas3[i]);
        //printf(lineas[i]);
    }
    fprintf(archivo,"\n-------------------------------------\n");

    fprintf(archivo,"\nEOF\n");

    /*printLineas1();
    printLineas2();
    printLineas3();*/

    fclose(archivo);

}
