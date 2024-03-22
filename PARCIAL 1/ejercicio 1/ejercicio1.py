# Crea una pila vacia
def Stack():
    return []

# Verifica si la pila no tiene elementos
def isEmptyStack(pila):
    return len(pila)==0

# Adiciona un valor a la pila (al final)
def push(pila, valor):
    pila.append(valor)

# Elimina un valor de la pila (el ultimo)
def pop(pila):
    if not isEmptyStack(pila):
        return pila.pop()
    else:
        print("Error: pila vacia")
        return []

# Consulta el ultimo valor de la pila sin sacarlo
def top(pila):
    if not isEmptyStack(pila):
        return pila[-1]
    else:
        print("Error: pila vacia")
        return []

# Retorna la cantidad de elementos en la pila
def sizeStack(pila):
    return len(pila)

#-------------------------------------------------------

def mostrarFibonaci():
    n = 10
    fib1= 1
    fib2 = 1
    
    pila = Stack();
    
    push(pila, fib1);
    push(pila, fib2);
    
    for _ in range(2,n):
        fib_suma = fib1 + fib2;
        push(pila, fib_suma);
        fib1 = fib2
        fib2=fib_suma
        
        
    # Muestra los términos de Fibonacci en la pila
    print("Los primeros", n, "términos de Fibonacci son:")
    while not isEmptyStack(pila):
        print(pop(pila), end=" ")
    print()
    

mostrarFibonaci()    