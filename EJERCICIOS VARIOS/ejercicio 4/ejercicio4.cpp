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
    return 0;
}

int main()
{
    int numero;
    scanf("%d", &numero);
    printf("%d", numero);

    calcularDivisores(numero);

    return 0;
}