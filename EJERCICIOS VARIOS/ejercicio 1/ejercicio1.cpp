#include <stdio.h>
bool ternaPitagorica(int a, int b, int c)
{
    return a * a + b * b == c * c;
}

int ciclo_terna_pitagorica()
{

    for (int lado1 = 1; lado1 <= 500; lado1++)
        for (int lado2 = 1; lado2 <= 500; lado2++)
            for (int lado3 = 1; lado3 <= 500; lado3++)
            {
                if (ternaPitagorica(lado1, lado2, lado3))
                    printf("Ternas pitoagoricas encontrads: (%d,%d,%d)\n", lado1, lado2, lado3);
            }
}

int main(void)
{
    //    if(ternaPitagorica(3,4,5)){
    //     printf("Es una terna pitagorica");
    //    }else{
    //     printf("No es una terna pitagorica");
    //    }
    ciclo_terna_pitagorica();
    return 0;
}
