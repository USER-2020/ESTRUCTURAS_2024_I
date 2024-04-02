#include "TADpilas.h"
#include "TADcolas.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para verificar si un carácter es un operador
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Función para convertir una expresión entrefija a postfija
char *enfix_to_postfix(char *expression)
{
    // Verificar si la expresión contiene al menos un operador
    // bool has_operator = false;
    // for (int i = 0; expression[i] != '\0'; ++i)
    // {
    //     if (isOperator(expression[i]))
    //     {
    //         has_operator = true;
    //         break;
    //     }
    // }

    // Si no hay operadores, devolver la expresión como una cadena
    // if (!has_operator)
    // {
    //     printf("No hay operadores\n");
    //     char *number_expression = (char *)malloc(sizeof(char) * (strlen(expression) + 1));
    //     strcpy(number_expression, expression);
    //     printf(number_expression);
    //     return number_expression;
    // }

    // Continuar con el código original para convertir la expresión a postfix
    StackType operator_stack = Stack();
    QueueType output_queue = Queue();
    char *postfix_expression = (char *)malloc(sizeof(char) * (strlen(expression) + 1));
    // La funcion strlen devuleve el tamanio  del string sin contar el \0  y malloc  reserva memoria para el char
    int postfix_index = 0;

    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (expression[i] == '(')
        {
            push(operator_stack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!isEmptyStack(operator_stack) && top(operator_stack) != '(')
            {
                inQueue(output_queue, pop(operator_stack));
            }
            pop(operator_stack); // Descartamos el '('
        }
        else if (isOperator(expression[i]))
        {
            while (!isEmptyStack(operator_stack) && top(operator_stack) != '(')
            {
                inQueue(output_queue, pop(operator_stack));
            }
            push(operator_stack, expression[i]);
        }
        else if (expression[i] >= '0' && expression[i] <= '9')
        {
            inQueue(output_queue, expression[i]);
        }
    }

    while (!isEmptyStack(operator_stack))
    {
        inQueue(output_queue, pop(operator_stack));
    }

    while (!isEmptyQueue(output_queue))
    {
        postfix_expression[postfix_index++] = deQueue(output_queue);
    }

    postfix_expression[postfix_index] = '\0'; // Agregamos el terminador nulo al final del postfix este terminador existe en c++ por el tema de fianl de cadena
    return postfix_expression;
}

// Función para evaluar una expresión postfix
int evaluatePostfix(char* expression)
{
    // Verificar si la expresión contiene al menos un operador
    bool has_operator = false;
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (isOperator(expression[i]))
        {
            has_operator = true;
            break;
        }
    }

    // Si no hay operadores, devolver el número de la expresión
    if (!has_operator)
    {
        int number = 0;
        int sign = 1; // Para manejar números negativos 1 positivo -1 negativo
        int i = 0;
        if (expression[0] == '-')
        {
            sign = -1;
            ++i;
        }
        while (expression[i] != '\0')
        {
            number = number * 10 + (expression[i] - '0');//Devuleve el valor entero de la expresion
            ++i;
        }
        return sign * number;
    }

    // Si hay operadores, evaluar la expresión normalmente
    StackType operand_stack = Stack();

    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (isdigit(expression[i]))
        {
            push(operand_stack, expression[i] - '0');//Devuleve el valor entero de la expresion
        }
        else if (isOperator(expression[i]))
        {
            int operand2 = pop(operand_stack);
            int operand1 = pop(operand_stack);
            switch (expression[i])
            {
            case '+':
                push(operand_stack, operand1 + operand2);
                break;
            case '-':
                push(operand_stack, operand1 - operand2);
                break;
            case '*':
                push(operand_stack, operand1 * operand2);
                break;
            case '/':
                push(operand_stack, operand1 / operand2);
                break;
            }
        }
    }

    return pop(operand_stack);
}

int main()
{
    // Expresiones infix de prueba
    char *expression1 = "3+4*5";
    char *expression2 = "(3+2)*(5-2)";
    char *expression3 = "2+5";
    char *expression4 = "43343";
    
    printf("Expresion 1 en postfix: %s\n", enfix_to_postfix(expression1));
    printf("Resultado de la expresion 1: %d\n", evaluatePostfix(enfix_to_postfix(expression1)));
    printf("Expresion 2 en postfix: %s\n", enfix_to_postfix(expression2));
    printf("Resultado de la expresion 2: %d\n", evaluatePostfix(enfix_to_postfix(expression2)));
    printf("Expresion 3 en postfix: %s\n", enfix_to_postfix(expression3));
    printf("Resultado de la expresion 3: %d\n", evaluatePostfix(enfix_to_postfix(expression3)));
    printf("Expresion 4 en postfix: %s\n", enfix_to_postfix(expression4));
    printf("Resultado de la expresion 4: %d\n", evaluatePostfix(enfix_to_postfix(expression4)));

    return 0;
}