#include <stdio.h>

int inverseNumber()
{
    int number;
    printf("\nIngrese el numero a invertir: ");
    scanf("%d", &number);

    printf("Numero a invertr:  %d", number);  //Imprime el numero original
    int newNumber, cifra;
    newNumber = 0;
    cifra = 0;

    while(number != 0){
        cifra = number % 10;
        newNumber = newNumber * 10 + cifra;   //Muestra la ultima cifra
        number = number / 10;
    }
    

    
    printf("\nEste el numero invertido: %d", newNumber);
}

int main(){
    inverseNumber();
    return 0;
}