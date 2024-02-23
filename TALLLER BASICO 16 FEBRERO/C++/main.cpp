#include <stdio.h>
#include <math.h>

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
        printf("pos [%d]: ", i + 1);
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

            printf("Numero posicion i[%d]: %d\n", i + 1, numbers[i]);
            printf("Numero posicion j[%d]: %d\n", j, numbers[j]);
            if (numbers[i] == numbers[j])
            {

                countMap[i][1]++;
                printf("se repite: %d\n", countMap[i][0]);
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
    if (maxRepetitions > 1)
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
            printf("\nIngrese el valor de la pos -> [%d][%d]: ", i + 1, j + 1);
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
            // printf("Matrix en la posicion [%d][%d]: ", i, i);
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

    printf("\nLa matriz   \n");
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
            printf("Resultado de %d %% %d = %d\n", number, i, r);
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
    printf("Estos son los facotres primos de %d: \n", numero);
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

/* Ejercicio 5 */
int pointProduct()
{
    int sizeVector;
    printf("Ingrese el tamnio del vector: ");
    scanf("%d", &sizeVector);

    /* Cual es la diferencia enttre vestor y arreglo(?) */
    /* El vector es una estructura de datos que permite almacenar un conjunto de valores de distinto tipo,
      mientras que el arreglo es una secuencia linear de elementos todos de un solo tipo de dato. */
    int vectorA[sizeVector]; /* Declaracion de un vector dinamico */
    int vectorB[sizeVector];
    printf("Ingrese valores para el vector A: \n");
    for (int x = 0; x < sizeVector; x++)
    {
        printf("Posicion %d: ", x + 1);
        scanf("%d", &vectorA[x]);
    }
    printf("Vector A: ");
    for (int x = 0; x < sizeVector; x++)
    {
        printf("%d ", vectorA[x]);
    }
    printf("\n");

    printf("Ingrese valores para el vector B: \n");
    for (int x = 0; x < sizeVector; x++)
    {
        printf("Posicion %d: ", x + 1);
        scanf("%d", &vectorB[x]);
    }
    printf("Vector B: ");
    for (int x = 0; x < sizeVector; x++)
    {
        printf("%d ", vectorB[x]);
    }
    printf("\n");

    /* Ahora hacemos el producto punto */
    int result = 0;
    for (int i = 0; i < sizeVector; i++)
    {
        /* Sumatoria de los productos en la pocision
        de la iteracion += incremntar(sumatoria)*/
        result += vectorA[i] * vectorB[i];
    }
    printf("Este es el resultado de la operacion punto : %d\n", result);
}

/* Ejercicio 6 */
const int MAX_ROWS = 10;
const int MAX_COLS = 10;

int sumMatrices()
{
    int matrizA[MAX_ROWS][MAX_COLS];
    int matrizB[MAX_ROWS][MAX_COLS];
    int resultado[MAX_ROWS][MAX_COLS];
    int files, columns;

    printf("\nIngrese el numero de filas de la matriz : ");
    scanf("%d", &files);

    printf("\nIngrese el numero de columnas de la matriz : ");
    scanf("%d", &columns);

    printf("\nIngrese los valores de la matriz A: \n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Matriz A -> pos[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizA[i][j]);
        }
    }
    printf("\nMatriz A ingresada:\n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%5d ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\nIngrese los valores de la matriz B: \n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Matriz B -> pos[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizB[i][j]);
        }
    }
    printf("\nMatriz B ingresada:\n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%5d ", matrizB[i][j]);
        }
        printf("\n");
    }

    /* Sumar las matrices  */
    printf("\nMatriz resultante después de la suma:\n");
    for (int i = 0; i < files; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
            printf("%5d ", resultado[i][j]);
        }
        printf("\n");
    }
}

/* Ejercicio 7 */
int multMatrices()
{
    int matrizA[MAX_ROWS][MAX_COLS];
    int matrizB[MAX_ROWS][MAX_COLS];
    int resultado[MAX_ROWS][MAX_COLS];
    int files, columns;

    printf("\nIngrese el numero de filas de la matriz : ");
    scanf("%d", &files);

    printf("\nIngrese el numero de columnas de la matriz : ");
    scanf("%d", &columns);

    printf("\nIngrese los valores de la matriz A: \n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Matriz A -> pos[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizA[i][j]);
        }
    }
    printf("\nMatriz A ingresada:\n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%5d ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\nIngrese los valores de la matriz B: \n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Matriz B -> pos[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizB[i][j]);
        }
    }
    printf("\nMatriz B ingresada:\n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%5d ", matrizB[i][j]);
        }
        printf("\n");
    }

    /* Multiplicar las matrices  */
    printf("\nMatriz resultante después de la multiplicacion:\n");
    for (int i = 0; i < files; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            resultado[i][j] = matrizA[i][j] * matrizB[i][j];
            printf("%5d ", resultado[i][j]);
        }
        printf("\n");
    }
}

/* Ejercicio 8 */
int inverseNumber()
{
    int number;
    printf("\nIngrese el numero a invertir: ");
    scanf("%d", &number);

    // printf("Numero a invertr:  %d", number); // Imprime el numero original
    int newNumber, cifra;
    newNumber = 0;
    cifra = 0;

    while (number != 0)
    {
        cifra = number % 10;
        newNumber = newNumber * 10 + cifra; // Muestra la ultima cifra
        number = number / 10;
    }

    printf("\nEste es el numero invertido: %d", newNumber);
}

/* Ejercicio 9 */
int changueEnteroToBinary()
{
    int n, binario[10], longitud;
    printf("\nIngrese un # entero mayor que 0 : ");
    scanf("%d", &n);

    longitud = 0;
    while (n > 0)
    {
        /* En cada iteración del bucle, se toma el residuo de la división numero % 2 (es decir, el último dígito binario)
        y se almacena en la posición actual del array binario. Luego, incrementa la variable longitud para apuntar a la
        siguiente posición del array. */
        binario[longitud++] = n % 2;
        /* Imprimimos el valor de la longitud por cada iteracion */
        printf("Longitud actual: %d\n", longitud);
        /* Imprimiemos el valor de n parqa corroborar que siempre es mayor que 0 */
        printf("Numero  actual: %d\n", n);
        /* Imprimimos el valor binario en la posicion anterior de la longitud actual */
        printf("binario en la pocision [%d]: %d\n", longitud, binario[longitud - 1]);
        n /= 2;
        printf("numero  actual despues de / entre 2: %d\n", n); // Muestra el número en cada iteración ccuando llega a 0 se dale del ciclo
    }
    printf("La longitud despues de obtner 0 en el while: %d\n", longitud);
    printf("La longitud despues de obtner 0 en el while en la ultima posicion  del array: %d\n", longitud - 1);
    printf("El resultado en binario es : ");
    for (int i = longitud - 1; i >= 0; --i)
    {
        printf("%d", binario[i]);
    }
    printf("\n");
}

/* Ejercicio 10 */
int changueBinary()
{
    int n, vector[10], suma, potencia;
    printf("\nCantiad de cifras: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nCifra : %d  del numero : ", i + 1);
        scanf("%d", &vector[i]);
    }
    printf("\n\nVector completo: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    suma = 0;
    potencia = 0;
    for (int x = n - 1; x >= 0; x--)
    {
        suma += pow(2, potencia) * vector[x];
        printf("Suma con potencia %d: %d \n", potencia, suma);
        potencia++;
    }

    printf("\nEl numero en base 10 es : %d", suma);
}

/* Ejercicio 11 */
int periferiSumaMatrix()
{
    int matriz[MAX_ROWS][MAX_COLS];
    int resultado[MAX_ROWS][MAX_COLS];
    int files, columns;

    printf("\nIngrese el numero de filas: ");
    scanf("%d", &files);
    printf("\nIngrese el numero de columnas: ");
    scanf("%d", &columns);

    /* Llenar matrix A */
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            /* code */
            printf("Ingrese los valores de la Matriz A en la pos -> [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int sumatoria = 0;
    // for (int i = 0; i < files; i++)
    // {
    //     /* code */
    //     for (int j = 0; j < columns; j++)
    //     {
    //         /* code */
    //         sumatoria += matriz[i][j];
    //             }
    // }
    // printf("La sumatoria es igual a : %d", sumatoria);
    /* Sumar primera fila y utilma fila */
    for (int i = 0; i < columns; ++i)
    {
        sumatoria += matriz[0][i];
        sumatoria += matriz[files - 1][i];
    }
    /* Sumar primera columna y utilma columna
    menos la primera fila poreso empieza en 1 y menos
    la ultikma fila poir eso va hasta files -1 */
    for (int i = 1; i < files - 1; ++i)
    {
        sumatoria += matriz[i][0];
        sumatoria += matriz[i][columns - 1];
    }

    printf("Este es el valor de la sumatoria de los valores externos (periferia): %d", sumatoria);
}

/* Ejercicio 12 */
int matrizTranspuesta()
{
    int matriz[MAX_ROWS][MAX_COLS];
    /* Como es cuadrada es la misma */
    int dimension;

    printf("Ingrese  el tamaño de la matriz: ");
    scanf("%d", &dimension);

    printf("\nEl tmanio de la matriz sera: %d x %d", dimension, dimension);

    printf("\nIngrese  los numeros para la matriz:\n");
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; j++)
        {
            /* code */
            printf("Ingrese los valores de la Matriz A en la pos -> [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nEsta es la matriz a evaluar\n");
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }

    // /* Invertir la matriz */
    // for (int i = 0; i < dimension; i++)
    // {
    //     for (int j = i + 1; j < dimension; j++)
    //     {
    //         // Intercambiar elementos [i][j] y [j][i] sin usar variable temporal
    //         matriz[i][j] = matriz[i][j] + matriz[j][i];
    //         matriz[j][i] = matriz[i][j] - matriz[j][i];
    //         matriz[i][j] = matriz[i][j] - matriz[j][i];
    //     }
    // }

    printf("\nEsta es la matriz transpuesta:\n");
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            /* Se cambia la posicion de la filas por las columnas
            entonces se muestran enlas filas las columnas y en las
            filas las columnas */
            printf("%5d ", matriz[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("                         ______                     \n");
    printf(" _________        .---\"\"\"      \"\"\"---.              \n");
    printf(":______.-':      :  .--------------.  :             \n");
    printf("| ______  |      | :                : |             \n");
    printf("|:______B:|      | |  Estructuras   | |             \n");
    printf("|:______B:|      | |                | |             \n");
    printf("|:______B:|      | |      2024      | |             \n");
    printf("|         |      | |                | |             \n");
    printf("|:_____:  |      | |                | |             \n");
    printf("|    ==   |      | :                : |             \n");
    printf("|       O |      :  '--------------'  :             \n");
    printf("|       o |      :'---...______...---'              \n");
    printf("|       o |-._.-i___/'             \\._             \n");
    printf("|'-.____o_|   '-.   '-...______...-'  `-.          \n");
    printf(":_________:      `.____________________   `-._____.- \n");
    printf("                 .'.eeeeeeeeeeeeeeeeee.'.      :___:   \n");
    printf("    fsc        .'.eeeeeeeeeeeeeeeeeeeeee.'.            \n");
    printf("              :____________________________:           \n");

    printf("\n\n");

    while (true)
    {
        printf("\nMenu\n");
        printf("1. Leer un conjunto de valores (números enteros), almacenarlos en un arreglo, y "
               "posteriormente encontrar y mostrar el elemento qué más se repite al interior del "
               "arreglo. Además, debe mostrar la cantidad de veces que se repite.\n");
        printf("2. Leer una matriz de números flotantes y, debe encontrar el mayor valor que se "
               "encuentra tanto en la diagonal principal como en la diagonal secundaria (debe mostrar"
               "los dos valores).\n");
        printf("3. Dado un número entero positivo, determinar si cumple con ser un número primo.\n");
        printf("4. Dado un número entero positivo calcular y mostrar los factores primos que lo "
               "conforman.\n");
        printf("5. Dados dos vectores con números enteros (de la misma dimensión), debe calcular, y "
               "mostrar el producto punto resultante de esos dos vectores.");
        printf("6. Leer dos matrices de números enteros y debe calcular y mostrar la suma de las dos "
               "matrices.\n");
        printf("7. Leer dos matrices de números enteros y debe calcular y mostrar la multiplicación de "
               "las dos matrices.\n");
        printf("8. Dado un vector, debe invertir el contenido de sus posiciones y mostrarlo.\n");
        printf("9. Dado un número entero positivo (en base 10), calcular su correspondiente valor en "
               "base 2 (binario), lo debe almacenar en un vector.\n");
        printf("10. Dado un número binario, representado por un vector con valores 1 ó 0 en cada una de "
               "sus posiciones, debe calcular el correspondiente resultado en base 10.\n");
        printf("11. Dada una matriz de números flotantes o reales de tamaño m x n (no necesariamente "
               "cuadrada), debe calcular y mostrar la suma de los valores que se encuentran en la "
               "periferia de la misma. La periferia está conformada por la primera fila, la última fila, la "
               "primera columna y la última columna.\n");
        printf("12. Dada una matriz cuadrada de números enteros, debe calcular en la misma matriz sin "
               "utilizar matrices auxiliares, la matriz transpuesta (se intercambian filas por columnas). "
               "Debe mostrar el resultado obtenido.\n");
        printf("0. Salir...\n");
        printf("\nQue quieres hacer? -> ");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            repeatingNumber();
            break;
        case 2:
            readMatrix();
            break;
        case 3:
            esPrimo();
            break;
        case 4:
            getPrimesFactories();
            break;
        case 5:
            pointProduct();
            break;
        case 6:
            sumMatrices();
            break;
        case 7:
            multMatrices();
            break;
        case 8:
            inverseNumber();
            break;
        case 9:
            changueEnteroToBinary();
            break;
        case 10:
            changueBinary();
            break;
        case 11:
            periferiSumaMatrix();
            break;
        case 12:
            matrizTranspuesta();
            break;
        case 0:
            printf("Saliendo del programa...");
            return 0;

        default:
            printf("Opcion no valida, intentalo de nuevo\n");
            break;
        }
    }

    // pointProduct();
    // sumMatrices();
    // multMatrices();
    // inverseNumber();
    // changueEnteroToBinary();
    // periferiSumaMatrix();
    // matrizTranspuesta();
    // repeatingNumber();
    // readMatrix();
    // esPrimo();
    // getPrimesFactories();
    // changueBinary();
    // int x = 10;
    // printf("\n1. Valor de x : %d", x++);
    // printf("\n2. Valor de x : %d", ++x);
    // printf("\n3. Valor de x : %d", x+=1);
    // printf("\n5. Valor de x : %d", x+1);
    // printf("\n5. Valor de x : %d", x);
    return 0;
}