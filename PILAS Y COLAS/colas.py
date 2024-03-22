# ----------------------------------------------------------------------
# Primitivas de la cola TAD-cola
# ----------------------------------------------------------------------
# Crea una cola vacia

from pilas import Stack, push, pop

def Queue():
    return []

# Verifica si la cola no tiene elementos
def isEmptyQueue(cola):
    return len(cola)==0

# Adiciona un valor a la cola (al final)
def inQueue(cola, valor):
    cola.append(valor)

# Elimina un valor de la cola (el primero)
def deQueue(cola):
    if not isEmptyQueue(cola):
        return cola.pop(0)
    else:
        print("Error: cola vacia")
        return []

# Consulta el primer valor de la cola sin sacarlo
def frontQueue(cola):
    if not isEmptyQueue(cola):
        return cola[0]
    else:
        print("Error: cola vacia")
        return []

# Retorna la cantidad de elementos en la cola
def sizeQueue(cola):
    return len(cola)

# ----------------------------------------------------------------------

# Muestra el contenido de una cola
def mostrarCola(cola):
    print("\nLos valores de la cola son : ")
    temp=Queue()
    while not isEmptyQueue(cola):
        valor=deQueue(cola)
        inQueue(temp,valor)
        print(valor,end=",")
    while not isEmptyQueue(temp):
        inQueue(cola,deQueue(temp))
    print("\n")

# Elimina un valor determinado de una cola
def eliminarUno(cola, dato):
    temp=Queue()
    while not isEmptyQueue(cola):
        valor=deQueue(cola)
        if valor != dato:
            inQueue(temp,valor)
    while not isEmptyQueue(temp):
        inQueue(cola,deQueue(temp))

# Suma los valores de una cola
def sumarCola(cola):
    temp=Queue()
    suma=0
    while not isEmptyQueue(cola):
        valor=deQueue(cola)
        suma += valor
    while not isEmptyQueue(temp):
        inQueue(cola,deQueue(temp))
    return suma

# Invierte el contenido de una cola con una pila
def invertirCola(cola):
    pila=Stack()
    while not isEmptyQueue(cola):
        push(pila,deQueue(cola))
    while not isEmptyQueue(pila):
       inQueue(cola,pop(pila))


# Operaciones con la Cola
"""
cola=Queue()
for i in range(20):
    inQueue(cola,i)

mostrarCola(cola)
print("\nCantidad de elementos : ",size(cola))
"""
# Ejemplos 1
"""
cola=Queue()
for i in range(10,51,10):
    inQueue(cola,i)
mostrarCola(cola)
print("La cantidad de elementos es : ",sizeQueue(cola))
eliminarUno(cola,30)
mostrarCola(cola)
print("El primer elemento es : ",frontQueue(cola))
print("La cola esta vacia : ",isEmptyQueue(cola))
"""

#Ejemplos 2
cola=Queue()
n=5
for x in range(n):
    valor=x+1
    inQueue(cola,valor)

mostrarCola(cola)
print("\nInvirtiendo la cola : ")
invertirCola(cola)
mostrarCola(cola)

print("\nLa suma de los valores es : ",sumarCola(cola))

divisibles=0
while not isEmptyQueue(cola):
    dato=deQueue(cola)
    if dato%5==0:
        divisibles += 1
print("La cantidad de divisores : ",divisibles)

if isEmptyQueue(cola):
    print("\nLa cola esta vacia")
else:
    print("\nLa cola no esta vacia")