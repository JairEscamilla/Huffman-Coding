// Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>

// Definicion de las estructuras
typedef struct defLista{
  char simbolo, codigo[100];
  int probabilidad, status, lista;
  struct defLista* sig;
}TipoLista;
// Prototipos de funciones
void menu();
// Funcion principal
int main() {
  menu();
  return 0;
}

// Desarrollando las funciones
void menu(){
  printf("\t\t\t Codificacion de Huffman\n");
  printf("\t1.- Introducir simbolo\n");
  printf("\t2.- Listar simbolos\n");
  printf("\t3.- Borrar simbolo\n");
  printf("\t4.- Modificar simbolo\n");
  printf("\t5.- Guardar simbolos en archivo\n");
  printf("\t6.- Leer simbolos de archivo\n");
  printf("\t7.- Generar códigos\n");
  printf("\t8.- Codificar mensaje\n");
  printf("\t9.- Decodificar mensaje\n");
  printf("\t10.- Salir\n");
  printf("\nDel anterior menu, selecciona la opcion deseada-> ");
}
