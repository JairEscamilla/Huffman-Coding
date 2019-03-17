// Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>

// Definicion de las estructuras
typedef struct defLista{
  char simbolo, codigo[100];
  int probabilidad, status, tipo;
  struct defLista* sig;
}TipoLista;
// Prototipos de funciones
void menu();
void creditos();
void agregar(TipoLista**);
void listar(TipoLista*);
void borrar(TipoLista**);
// Funcion principal
int main() {
  int opcion;
  TipoLista* Inicio = NULL;
  creditos();
  do {
    menu();
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        agregar(&Inicio);
        break;
      case 2:
        listar(Inicio);
        break;
      case 3:
        borrar(&Inicio);
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        printf("Saliendo del programa...\n");
        exit(0);
        break;
      default:
        printf("Ingresa una opcion valida!\n");
    }
    printf("Presiona enter para continuar...");
    __fpurge(stdin);
    getchar();
  } while(opcion != 10);
  return 0;
}   

// Desarrollando las funciones
void menu(){
  system("clear");
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
void creditos(){
  system("clear");
  printf("\t\t\t Codificacion de Huffman\n");
  printf("Desarrollado por:\n\tCesar Mauricio Arellano Velasquez\n\tRaul Gonzalez Portillo\n\tAllan Jair Escamilla Hernandez\n\n");
  printf("Presione una tecla para continuar...");
  getchar();
  system("clear");
  printf("Objetivo: Codificar y decodificar mensajes usando la codificacion de Huffman.\n");
  printf("Presione una tecla para continuar...");
  getchar();
}
void agregar(TipoLista** Inicio){
  char caracter;
  int probabilidad;
  TipoLista* Nuevo = (TipoLista*)malloc(sizeof(TipoLista));
  TipoLista* temp;
  system("clear");
  printf("Ingresar un caracter: ");
  __fpurge(stdin);
  caracter = getchar();
  printf("Ingresar la probabilidad de aparicion: ");
  scanf("%d", &probabilidad);
  Nuevo->simbolo = caracter;
  Nuevo->probabilidad = probabilidad;
  Nuevo->status = 0;
  Nuevo->tipo = 0;
  Nuevo->sig = NULL;
  if(*Inicio == NULL){
    *Inicio = Nuevo;
  }else{
    temp = *Inicio;
    while(temp->sig != NULL){
      temp = temp->sig;
    }
    temp->sig = Nuevo;
  }
}
void listar(TipoLista* Inicio){
  system("clear");
  printf("\t\t\t Codificacion de Huffman\n");
  TipoLista* temp = Inicio;
  while (temp != NULL) {
    printf("\tCaracter: %c. Probabilidad: %d.\n", temp->simbolo, temp->probabilidad);
    temp = temp->sig;
  }
  printf("\n");
}
void borrar(TipoLista** Inicio){
  system("clear");
  char simbolo;
  TipoLista* aux = *Inicio, *ant = NULL;
  printf("Ingresar el simbolo a borrar: ");
  __fpurge(stdin);
  simbolo = getchar();
  while ((aux != NULL) && (aux->simbolo != simbolo)) {
    ant = aux;
    aux = aux->sig;
  }
  if (aux!=NULL) {
    if (ant!=NULL) {
      ant->sig = aux->sig;
    }else{
      *Inicio = aux->sig;
    }
    free(aux);
  }
}
