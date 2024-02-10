#include <stdio.h>

int main(void){
    int arreglo[] = {1,8,2,3,45};
    int posMayor = 0;
    int tamnio_total = sizeof(arreglo)/ sizeof(arreglo[0]);

    for(int i = 1; i<= tamnio_total ; i++){
        if(arreglo[i] > arreglo[posMayor]){
            posMayor = i;
        }
    }
    printf("el tamnio del arreglo es:  %d\n",tamnio_total);
    printf("La posicion del numero mayor es: %d\n", posMayor);
    return posMayor;
}