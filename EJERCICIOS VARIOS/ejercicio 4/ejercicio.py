def calcularDivisor():
    numero = input("Ingrese el numero a evaluar: ");
    a= int(numero);
    if a > 0:
        for i in range(1, a+1):
            if(a % i == 0):
               print(f"{i}", i);
            

calcularDivisor();

 