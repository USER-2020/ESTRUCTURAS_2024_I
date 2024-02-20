def main():
    arreglo = [1,8,25,4,5];
    posMayor = 0;
    tamanio_total = len(arreglo);
    
    for i in range(0,tamanio_total):
        if(arreglo[i] > arreglo[posMayor]):
            posMayor = i;
        
    
    print("La poscion del mas grande es: ", posMayor);
    print("El elemento mas grande es: ", arreglo[posMayor]);
    return posMayor;

main();