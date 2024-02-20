#include <stdio.h>

int calcularDivisores(int a)
{
    if (a > 0)
    {
        int sumatoria = 0;
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                // printf("%d ", i);
                sumatoria += i;
                
            }
        }
        return sumatoria;
    }
    return 0;
}

int main()
{
    int r= calcularDivisores(10);
    printf("La sumatoria es %d", r);
    return 0;
}