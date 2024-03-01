# ----------------------------------------------------------------------
# Primitivas de la pila TAD-pila
# ----------------------------------------------------------------------
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

# ----------------------------------------------------------------------

# Muestra el contenido de una pila
def mostrarPila(pila):
    print("\nEl contenido de la pila es :")
    temp=Stack()
    while not isEmptyStack(pila):
        valor=pop(pila)
        print(valor,end=",")
        push(temp,valor)
    while not isEmptyStack(temp):
        push(pila,pop(temp))

# Invierte los valores almacenados en una pila
def invertirPila(pila):
    temp1=Stack()
    temp2=Stack()
    while not isEmptyStack(pila):
        push(temp1,pop(pila))
    while not isEmptyStack(temp1):
        push(temp2,pop(temp1))
    while not isEmptyStack(temp2):
        push(pila,pop(temp2))

# Suma los elementos de una pila
def sumarPila(pila):
    temp=Stack()
    suma=0
    while not isEmptyStack(pila):
        valor = pop(pila)
        suma = suma + valor
        push(temp,valor)
    while not isEmptyStack(temp):
        push(pila,pop(temp))
    return suma

# Determina si una pila esta ordenada de forma ascendente (menor en el tope)
def ordenadaPila(pila):
    if isEmptyStack(pila):
        #Determinar si esta vacio
        return True
        #Si devuelve que esta vacio devuleve true porque no 
        # tiene elementos que organzar eso quiere decir que ya esta oprganizada
    else:
        #Se crea una pila temporal
        temp=Stack()
        #Inicializa un valor de ordenada en true
        ordenada=True
        #Se quita el elemento superior de la pila y se almacena en la variable pri
        pri=pop(pila)
        # Se añade pri a la pila temporal temp
        push(temp,pri)
        while not isEmptyStack(pila):
            #Inicia un bucle que continúa hasta que la pila original esté vacía
            seg=pop(pila)
            #Se quita el siguiente elemento de la pila original y se almacena en seg
            push(temp,seg)
            # Se añade seg a la pila temporal temp
            if pri > seg:
                #Valida si es mayor que
                ordenada=False
            else:
                pri=seg
        while not isEmptyStack(temp):
            #Minetras la pila temp no este vacia se llenara la original "pila" con cada elemento que se quite del temp
        	push(pila,pop(temp))
        return ordenada

# Calcula el mayor de una pila
def mayorPila(pila):
    if isEmptyStack(pila):
        return None
    else:
        temp=Stack()
        mayor=pop(pila)
        push(temp,mayor)
        while not isEmptyStack(pila):
            valor=pop(pila)
            push(temp,valor)
            if valor > mayor:
                mayor=valor
        while not isEmptyStack(temp):
            push(pila,pop(temp))
        return mayor

# Determina si una pila cumple con el orden relativo de fibonacci
def ordenFibo(pila):
    if sizeStack(pila)<2:
        return False
    else:
        temp=Stack()
        pri=pop(pila)
        push(temp,pri)
        seg=pop(pila)
        push(temp,seg)
        orden=True
        while orden and not isEmptyStack(pila):
            valor=pop(pila)
            push(temp,valor)
            if valor != pri+seg:
                orden=False
            else:
                pri=seg
                seg=valor
        while not isEmptyStack(temp):
            push(pila,pop(temp))
        return orden

# Ordena una pila de forma ascendente
def ordenarPila(pila):
    if sizeStack(pila)>1:
        temp=Stack()
        cambios=True
        while cambios:
            pri=pop(pila)
            cambios=False
            while not isEmptyStack(pila):
                seg=pop(pila)
                if pri<=seg:
                    push(temp,pri)
                    pri=seg
                else:
                    push(temp,seg)
                    cambios=True
            push(temp,pri)
            while not isEmptyStack(temp):
                push(pila,pop(temp))


    
# Ejercicios 1
"""
p=Stack()
push(p,10)
push(p,20)
push(p,30)
push(p,40)
print(sizeStack(p))
print(pop(p))
print(top(p))
print(isEmptyStack(p))
"""

#Ejercicios 2
"""
p = Stack()
n=int(input("Cantidad de elementos: "))
for i in range(n):
    push(p,int(input("Ingrese un numero entero: ")))

print(sizeStack(p))
contador=0
while not isEmptyStack(p):
      valor = pop(p)
      if valor % 5 == 0:
          contador += 1
print("Cantidad de numeros divisibles por 5: ",contador)

if isEmptyStack(p):
    print("La pila esta vacia. ")
else:
    print("La pila no esta vacia.")
"""

"""
pila=Stack()
for x in range(1,6,1):
    push(pila,x)

mostrarPila(pila)
invertirPila(pila)
mostrarPila(pila)
print("\n\nLa suma es : ",sumarPila(pila))
print("\nEl mayor de la pila es : ",mayorPila(pila))
mostrarPila(pila)
"""
"""
# Ordenada pila
pila=Stack()
for x in range(20,5,-1):
    push(pila,x)

#push(pila,150)
#for x in range(5,0,-1):
#    push(pila,x)

mostrarPila(pila)
print("\nLa pila esta ordenada :  ",ordenadaPila(pila))
print("\nEl mayor de la pila es : ",mayorPila(pila))
"""

# Orden de fibonacci
pila=Stack()
push(pila,29)
push(pila,18)
push(pila,11)
push(pila,7)
push(pila,25)
push(pila,3)
mostrarPila(pila)
print("\nLa pila esta en orden ascendente : ",ordenadaPila(pila))
print("El mayor de la pila es : ",mayorPila(pila))
print("La pila esta en orden de fibonacci : ",ordenFibo(pila))

# Ordenar el contenido de una pila (tope es el menor)
"""
pila=Stack()
push(pila,9)
push(pila,18)
push(pila,111)
push(pila,7)
push(pila,4)
push(pila,53)
mostrarPila(pila)
ordenarPila(pila)
mostrarPila(pila)
"""


