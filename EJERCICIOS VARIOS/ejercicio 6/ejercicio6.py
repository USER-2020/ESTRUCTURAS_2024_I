def inverseNumber(a):
    newNumber = 0
    cifra = 0
    while(a != 0):
        cifra = a % 10
        newNumber = newNumber * 10 + cifra
        a = a // 10
    return newNumber

result = inverseNumber(138)
print(result)
