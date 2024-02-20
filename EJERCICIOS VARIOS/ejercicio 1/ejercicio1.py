def ternaPitagorica(a,b,c):
    return a**2 + b**2 == c**2

if ternaPitagorica(3,4,5):
    print("Es una terna pitagorica")
else:
    print("No es una terna pitagorica")
    
def ciclo_terna_pitagorica():
    for lado1 in range(1,501):
        for lado2 in range(1,501):
            for lado3 in range(1,501):
                if ternaPitagorica(lado1,lado2,lado3):
                    print(f"Terna pitagorica encontrada:  ({lado1}, {lado2}, {lado3})");
                    
ciclo_terna_pitagorica();