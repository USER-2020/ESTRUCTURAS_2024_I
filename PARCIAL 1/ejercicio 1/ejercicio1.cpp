#include <stdio.h>
#include <malloc.h>

typedef struct 
{
    int *data;
    int tope;
}Pila;

Pila crearPila(){
    Pila *p;
    p = (Pila*) malloc(sizeof(Pila));
    p->data=NULL;
    p->tope=0;
    return *p;
}

void push(Pila *p, int valor) {
    p->data = (int*) realloc(p->data, (p->tope + 1) * sizeof(int));
    p->data[p->tope++] = valor;
}

void mostrarPila(Pila p) {
    for (int i = 0; i < p.tope; i++) {
        printf("%d ", p.data[i]);
    }
    printf("\n");
}


int main(void){
    Pila p;
    p= crearPila();
    int terminos = 10;
    int fib1 = 1, fib2 = 1;
    for (int x=0; x<terminos; x++){
        push(&p, fib1);
        int next = fib1 + fib2;
        fib1 = fib2;
        fib2 = next;
    }

    mostrarPila(p);
    return 0;
}
