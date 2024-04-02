#include <stdio.h>
#include <malloc.h>

// Máxima cantidad de elementos que se pueden
// almacenar en la pila

#define MAX  20

typedef struct {
	int data[MAX];
	int tope;
}StackType;

// Crea una pila vacia
StackType Stack(void){
	StackType pila;
	pila.tope=0;
	return pila;
}

// Verifica si la pila no tiene elementos
bool isEmptyStack(StackType pila){
    return pila.tope==0;
}

// Adiciona un valor a la pila (al final)
void push(StackType &pila, int valor){
	if (pila.tope==MAX)
	    printf("\nPila llena, valor %d no adicionado",valor);
	else
    	pila.data[pila.tope++]=valor;
}

// Elimina un valor de la pila (el ultimo)
int pop(StackType &pila){
    if (not isEmptyStack(pila))
        return pila.data[--(pila.tope)];
	else {
        printf("Error: pila vacia");
        return NULL;
    }
}

// Consulta el ultimo valor de la pila sin sacarlo
int top(StackType pila){
    if (not isEmptyStack(pila))
        return pila.data[pila.tope-1];
    else {
        printf("\nError: pila vacia");
        return NULL;
    }
}

// Retorna la cantidad de elementos en la pila
int sizeStack(StackType pila) {
    return pila.tope;
}

