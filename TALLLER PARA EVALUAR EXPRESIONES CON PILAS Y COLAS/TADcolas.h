#include <stdio.h>
#include <malloc.h>

// Máxima cantidad de elementos que se pueden
// almacenar en la cola.

#define MAX  20

typedef struct {
	int data[MAX];
	int final;
}QueueType;

// Crea una cola vacia
QueueType Queue(void){
	QueueType cola;
	cola.final=0;
	return cola;
}

// Verifica si la cola no tiene elementos
bool isEmptyQueue(QueueType cola){
    return cola.final==0;
}

// Adiciona un valor a la cola (al final)
void inQueue(QueueType &cola, int valor){
	if (cola.final==MAX)
		printf("\nCola llena, valor: %d no adicionado",valor);
    else
    	cola.data[cola.final++]=valor;
}

// Elimina un valor de la cola (el primero)
// Desplaza todos los elementos una posición
int deQueue(QueueType &cola){
	int valor;
    if (not isEmptyQueue(cola)) {
    	valor=cola.data[0];
    	cola.final--;
        for (int i=0;i<cola.final;i++)
            cola.data[i]=cola.data[i+1];
        return valor;
    }
	else {
        printf("Error: cola vacia");
        return NULL;
    }
}

// Consulta el primer valor de la cola sin sacarlo
int frontQueue(QueueType cola){
    if (not isEmptyQueue(cola))
        return cola.data[0];
    else {
        printf("\nError: cola vacia");
        return NULL;
    }
}

// Retorna la cantidad de elementos en la cola
int sizeQueue(QueueType cola) {
    return cola.final;
}

