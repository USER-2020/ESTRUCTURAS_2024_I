def table():
    print("{:<10} {:<10} {:<10} {:<10}".format("Decimal", "Binario", "Octal", "Hexadecimal"))
    print("-" * 40)
    
    for decimal in range(1, 257):
        binario = bin(decimal)[2:]
        octal = oct(decimal)[2:]
        hexadecimal = hex(decimal)[2:].upper()
        
        print("{:<10} {:<10} {:<10} {:<10}".format(decimal, binario, octal, hexadecimal))
        
table()