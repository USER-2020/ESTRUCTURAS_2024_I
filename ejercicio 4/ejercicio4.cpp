#include <stdio.h>

int calcularDivisores(int a)
{

    if (a > 0)
    {
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                printf("%d ", i);
            }
        }
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);

    calcularDivisores(numero);

    return 0;
}