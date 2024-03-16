#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  if(arr == NULL || size <= 0) {
    return 0;
  }
  
  int elementoMayor = arr[0];
  
  for (int i = 0; i < size; i++) {
      if(arr[i] > elementoMayor) {
        elementoMayor = arr[i];
      }
    }
  return elementoMayor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  if(arr == NULL || size <= 0) {
    return;
  }
  int arr2[size];
  int indice = 0;
  for(int i = size - 1; i >= 0; i--){
      arr2[indice] = arr[i];
      indice++;
    }
  for(int k = 0; k < size; k++){
    arr[k] = arr2[k];
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize)
{
  int contadorPares = 0;
  for(int i = 0; i < size; i++)
    {
      if(arr[i] % 2 == 0)
      {
        contadorPares++;
      }
    }
  
  int *arr2 = (int *)malloc(contadorPares * sizeof(int));
  if(arr2 == NULL)
  {
    return NULL;
  }
  
  int indice = 0;
  for(int k = 0; k < size; k++)
    {
      if(arr[k] % 2 == 0)
      {
        arr2[indice] = arr[k];
        indice++;
      }
      if(indice == contadorPares)
          break;
    }
  *newSize = contadorPares;
  return arr2;
}



/*+
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
int nuevoTamano = size1 + size2;
int nuevoArr[nuevoTamano];
int i = 0;
int j = 0;
int k = 0;
 
while(i < size1 && k < size2)
  {
    if(arr1[i] <= arr2[k])
    {
      nuevoArr[j] = arr1[i];
      i++;
    }
    else
    {
      nuevoArr[j] = arr2[k];
      k++;
    }
    j++;
  }
//Comprobar si sobran elementos para agregarlos
  while(i < size1)
    {
      nuevoArr[j] = arr1[i];
      j++;
      i++;
    }
  while(k < size2)
    {
      nuevoArr[j] = arr2[k];
      j++;
      k++;
    }
  //Copiar el nuevo arreglo en el arreglo original
  for(int indice = 0; indice < nuevoTamano; indice++)
    {
      result[indice] = nuevoArr[indice];
    }
}                       

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int contadorAsc = 0;
  int contadorDesc = 0;

  for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] >= arr[i + 1])
          {
            contadorAsc++;
          }
          else
            break;
    }
  for(int i = 0; i < size - 1; i++)
    {
      if(arr[i] <= arr[i + 1])
          {
            contadorDesc++;
          }
    }
  
  if(contadorAsc == size - 1)
    return -1;
  else if(contadorDesc == size - 1)
    return 1;
  else
    return 0;
}



/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size)
{
  Nodo *cabeza = NULL; //Inicializo el primero y el ultimo en Null
  Nodo *ultimo = NULL;

  for(int i = 0; i < size; i++)
    {
      Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo)); //Reservo memoria para cada elemento en el arr
      if(nuevoNodo == NULL)
        exit(1);
      nuevoNodo->numero = arr[i]; //Almaceno el numero en el nodo, accediendo a su campo numero
      nuevoNodo->siguiente = NULL;//Al siguiente nodo lo inicializo en Null

      if(cabeza == NULL){ //Si la cabeza es Null, entonces el primer elemento es el nuevo nodo
        cabeza = nuevoNodo; //El nuevo nodo es la cabeza, pues es la primera vez que se crea
        ultimo = nuevoNodo; //Y al ser el unico a su veces, es el ultimo
      }
      else{
        ultimo->siguiente = nuevoNodo; //Si no es el primero, entonces el ultimo nodo apunta al nuevo nodo
        ultimo = nuevoNodo; //El nuevo nodo es el ultimo
      }
      
      }   
  return cabeza;
}
