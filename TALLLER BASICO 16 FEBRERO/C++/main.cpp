#include <stdio.h>

/* Ejercicio 1 */
int repeatingNumber()
{
    int sizeArray;
    printf("Ingrese el tamanio del arreglo: ");
    scanf("%d", &sizeArray);

    int numbers[sizeArray];

    // Leer el conjunto de valores
    printf("Ingrese %d números enteros:\n", sizeArray);
    for (int i = 0; i < sizeArray; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    // Utilizar un mapa no ordenado para contar las repeticiones
    /* int countMap[sizeArray][2];: Esto declara un array bidimensional llamado countMap
    de tamaño sizeArray por 2. Cada fila de countMap contendrá dos elementos:
    el valor del elemento y la cantidad de repeticiones. */
    int countMap[sizeArray][2];

    for (int i = 0; i < sizeArray; ++i)
    {
        /* countMap[i][0] = numbers[i];: Aquí se asigna el valor del elemento en la posición i del array numbers a
        la primera columna ([0]) de la fila i en countMap. En otras palabras, countMap[i][0] almacenará el valor
        del elemento en esa posición. */
        countMap[i][0] = numbers[i];
        /* countMap[i][1] = 1;: Inicializa la segunda columna ([1]) de la fila i en countMap con el valor 1.
        Esta columna se utilizará para contar la cantidad de repeticiones del elemento en la posición i. */
        countMap[i][1] = 1;

        for (int j = i + 1; j < sizeArray; ++j)
        {
            if (numbers[i] == numbers[j])
            {
                countMap[i][1]++;
            }
        }
    }

    // Encontrar el elemento que más se repite y la cantidad de repeticiones
    int mostRepeatedElement = -1;
    int maxRepetitions = 0;

    /* Esta parte del código itera a través de la matriz `countMap` para encontrar el elemento que es
    más repetido y el número de repeticiones que tiene */
    for (int i = 0; i < sizeArray; ++i)
    {
        if (countMap[i][1] > maxRepetitions)
        {
            mostRepeatedElement = countMap[i][0];
            maxRepetitions = countMap[i][1];
        }
    }

    // Mostrar el resultado
    /* Se pone -1 porque es una expresion regular contar con numeros positivos, es decir,
    no hay números negativos en este caso; porque  los indices de las matrices van desde 0 hasta sizeArray-1 */
    if (mostRepeatedElement != -1)
    {
        printf("El elemento que más se repite es: %d\n", mostRepeatedElement);
        printf("Se repite %d veces.\n", maxRepetitions);
    }
    else
    {
        printf("Todos los elementos son únicos.\n");
    }
}

/* Ejercicio 2 */
int readMatrix()
{
    int sizeFile;
    int sizeColumn;

    printf("Que tmanio quieres en las filas: ");
    scanf("%d", &sizeFile);

    printf("Que tamanio quieres en las columnas: ");
    scanf("%d", &sizeColumn);

    float matrix[sizeFile][sizeColumn];

    // Leer la matriz de números flotantes
    printf("Ingrese los valores de la matriz %dx%d:\n", sizeFile, sizeColumn);
    for (int i = 0; i < sizeFile; ++i)
    {
        for (int j = 0; j < sizeColumn; ++j)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Inicializar los mayores con los elementos de la primera fila y columna
    float maxDiagonalPrincipal = matrix[0][0];
    /* Se accede al ultimo numero de la columna en la misma fila */
    float maxDiagonalSecundaria = matrix[0][sizeColumn - 1];

    // Encontrar el mayor valor en la diagonal principal
    for (int i = 1; i < sizeFile; ++i)
    {
        if (matrix[i][i] > maxDiagonalPrincipal)
        {
            maxDiagonalPrincipal = matrix[i][i];
        }
    }

    // Encontrar el mayor valor en la diagonal secundaria
    for (int i = 1; i < sizeFile; ++i)
    {

        if (matrix[i][sizeColumn - 1 - i] > maxDiagonalSecundaria)
        {
            maxDiagonalSecundaria = matrix[i][sizeColumn - 1 - i];
        }
    }

    printf("La matriz   \n");
    for (int i = 0; i < sizeFile; ++i)
    {
        for (int j = 0; j < sizeColumn; ++j)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Mostrar los resultados
    printf("El mayor valor en la diagonal principal es: %.2f\n", maxDiagonalPrincipal);
    printf("El mayor valor en la diagonal secundaria es: %.2f\n", maxDiagonalSecundaria);
}

/* Ejercicio 3 */
int esPrimo()
{
    bool primo = true;
    int number;

    printf("Ingrese un numero positivo mayor que 0 --> ");
    scanf("%d", &number);

    if (number > 0)
    {
        // Verificar si el número es primo

        /* La elección de i * i en lugar de simplemente i es un truco común cuando se busca si un número es primo.
        Esto se debe a que, si hay algún divisor de number, debe estar entre 2 y la raíz cuadrada de number.
        Al usar i * i, nos ahorramos el cálculo de la raíz cuadrada y mejoramos la eficiencia del algoritmo */
        for (int i = 2; i * i <= number; ++i)
        {
            int r = number % i;
            printf("Resultado de %d %% %d = %d\n", number, i, r);
            if (number % i == 0)
            {
                primo = false; // Encontramos un divisor, no es primo
                break;
            }
        }

        // Imprimir el resultado
        if (primo)
        {
            printf("%d es un número primo.\n", number);
        }
        else
        {
            printf("%d no es un número primo.\n", number);
        }
    }
    else
    {
        printf("Por favor, ingrese un número positivo mayor que 0.\n");
    }
}

/* Ejercicio 4 */
int getPrimesFactories()
{
    int numero;
    printf("Ingrese el numero a evaluar: \n");
    scanf("%d", &numero);

    // Dividir el número por 2 mientras sea divisible por 2
    /* es decir que su resisudo sea cero */
    /* El bucle while (numero % 2 == 0) se ejecutará tantas veces como sea posible dividir numero por 2.
    En otras palabras, continuará ejecutándose mientras numero sea divisible por 2. Esto es parte de la factorización
    del número, identificando cuántas veces 2 es un factor del número. Luego, el bucle se detendrá cuando numero ya no
    sea divisible por 2. */
    while (numero % 2 == 0)
    {
        printf("2 ");
        /* numero /= 2;: Después de imprimir el factor primo 2,
        se divide numero por 2. Esto se hace para actualizar
        el valor de numero y continuar buscando otros factores
        primos de 2 en numero. */
        numero /= 2;
    }

    // Dividir el número por los impares mayores que 2
    /* Para hallar los factores primos siempre buscamos el numero por el que se pued dividir exactamente
     se evalua de el numero i = 3 hasta el numero ingresado*/
    for (int i = 3; i <= numero; i += 2)
    {
        while (numero % i == 0)
        {
            printf("%d ", i);
            /* Se divide el numero entre i que va ser el valor que va iterando
            para saber si hay mas factores del mismo tipo o numeros diferentes */
            numero /= i;
        }
    }

    printf("\n");
}

int pointProduct(){
    int sizeVector;
    printf("Ingrese el tamnio del vector: ");
    scanf("%d",&sizeVector);


    /* Cual es la diferencia enttre vestor y arreglo(?) */
    /* El vector es una estructura de datos que permite almacenar un conjunto de valores de distinto tipo,
      mientras que el arreglo es una secuencia linear de elementos todos de un solo tipo de dato. */

    int *vectorA[sizeVector];/* Declaracion de un vector dinamico */
    int *vectorB[sizeVector];
}

int main()
{
    // repeatingNumber();
    // readMatrix();
    // esPrimo();
    getPrimesFactories();
    return 0;
}