def inverseNumber(a):
    newNumber = 0
    cifra = 0
    while(a != 0):
        cifra = a % 10
        newNumber = newNumber * 10 + cifra
        # `a = a // 10` is performing integer division on the variable `a`. It divides the current
        # value of `a` by 10 and assigns the result back to `a`. This operation effectively removes
        # the last digit of the number stored in `a` by shifting all digits one place to the right.
        a = a // 10
    return newNumber

result = inverseNumber(138)
print(result)
