
# ESTRUCTURAS_2024_I

## Ejercicio 1:
Una "terna pitágorica" es el conjunto de los tres valores enteros correspondientes a los lados de una triangulo rectángulo. Estos tres lados deben de satisfacer la relación: de que la suma de los cuadrados de dos de los lados (cattetos) es igual al cuadrado de la hipotenusa.

Realizar un programaque encuentre todas las ternas pitágoricas para lado1, lado2 e hipotenusa, todos ellos no mayores de 500. Utilizar un lazo for de triple anidamiento, que pruebe todas las posibilidades.

## Ejercicio 2:
Conseguir la posicion de el numero mayor de un arreglo, sin utilzar las funciones de la api de los compiladores como son `min`, `max`, `prom`,etc...

## Ejercicio 3:
Escribir un programa que imprima una tabla de los equivalentes binarios, octal y hexadecimal de los numeros decimales en el rango del 1 al 256.

## Ejercicio 4:
Realizar un programa que me diga si un numero es abundante o no, un numero abundante es auel, que la suma de sus divisores es mayor que dos veces ese numero.

Ejemplo: n= 24, sus divisores son : 1, 2, 3, 4, 6, 8,  12, 24 la suma de sus divisores es: (1+2+3+4+6+8+12+24)= 60
2*n = 2*24 = 48
por lo tanto; 60 > 48, en conclusion el numero 24 es un numero abundante.

## Ejercicio 5:
Realizar un programa que ingrese desde el teclado dos numeros enteros positivos, para determinar si son amigo, Ejm(220, 284), ya que : los divisores propios de 220 son 1, 2, 4, 5, 10, 11 , 20, 22, 44, 55 y 110, que suman 284; los divisors propios de28 son 1, 2, 4, 7 y 142, que suman 220.

## Ejercicio 6:
Funcion que recibe un numero como parametro y devuleve el mismo numero pero inverso


# TALLER BASICO PROGRAMACION

Escriba un programa completo de tal manera que con base en el uso de menús permita 
resolver los siguientes problemas:

1. Leer un conjunto de valores (números enteros), almacenarlos en un arreglo, y 
posteriormente encontrar y mostrar el elemento qué más se repite al interior del
arreglo. Además, debe mostrar la cantidad de veces que se repite.
2. Leer una matriz de números flotantes y, debe encontrar el mayor valor que se 
encuentra tanto en la diagonal principal como en la diagonal secundaria (debe mostrar 
los dos valores).
3. Dado un número entero positivo, determinar si cumple con ser un número primo.
4. Dado un número entero positivo calcular y mostrar los factores primos que lo 
conforman.
5. Dados dos vectores con números enteros (de la misma dimensión), debe calcular, y 
mostrar el producto punto resultante de esos dos vectores.
6. Leer dos matrices de números enteros y debe calcular y mostrar la suma de las dos 
matrices.
7. Leer dos matrices de números enteros y debe calcular y mostrar la multiplicación de 
las dos matrices.
8. Dado un vector, debe invertir el contenido de sus posiciones y mostrarlo.
9. Dado un número entero positivo (en base 10), calcular su correspondiente valor en 
base 2 (binario), lo debe almacenar en un vector.
10. Dado un número binario, representado por un vector con valores 1 ó 0 en cada una de 
sus posiciones, debe calcular el correspondiente resultado en base 10.
11. Dada una matriz de números flotantes o reales de tamaño m x n (no necesariamente 
cuadrada), debe calcular y mostrar la suma de los valores que se encuentran en la 
periferia de la misma. La periferia está conformada por la primera fila, la última fila, la 
primera columna y la última columna.
12. Dada una matriz cuadrada de números enteros, debe calcular en la misma matriz sin 
utilizar matrices auxiliares, la matriz transpuesta (se intercambian filas por columnas). 
Debe mostrar el resultado obtenido.

# PILAS 
Tipos de datos abstractos
## Ejemplo 1:
1) Crear una pila e incluirle los valores:
10, 20, 30, 40, 50.
2) Determinar la cantidad de elementos.
3) Eliminar el último elemento
4) Mostrar el elemento que está en el tope de la pila. 
5) Saber si la pila está vacía

# TALLLER PARA EVALUAR EXPRESIONES CON PILAS Y COLAS

Se debe resolver el problema de convertir expresión matemática de entrefijo a posfijo y evaluarla, utilizando pilas y colas.

Dada una expresión matemática representada como una cadena de caracteres que se encuentra en entre-fijo, donde los operadores se encuentran entre los operandos (Ejm 12 + 23), debe convertirla a una expresión posfijo con operadores después de los operandos  (12  23 +) - la debe mostrar, y posteriormente debe evaluarla y presentar el respectivo resultado.

Solo debe utilizar las estructuras de datos pilas y colas con las primitivas vistas en el curso y sin utilizar ninguna estructura de datos adicional. 

Las operaciones que se deben implementar son suma (+), resta (-), multiplicación (*), división (/), y adicionalmente se puede tener cualquier cantidad de paréntesis que agrupe a las operaciones.


Ejemplo: dadas las siguientes expresiones

1) 2+5, debe mostrar 2 5 + y como resultado 7
2) ((3+2)*(5-2)), debe mostrar 3 2 + 5 2 - *, y como resultado 15
3) 125, debe mostrar 125 y como resultado 125
Debe probarlo con todas las oeraciones y diferentes longitudes de expresiones y prevenir posibles errores en la división.


