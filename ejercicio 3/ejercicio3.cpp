#include <stdio.h>

void imprimirBinario(int decimal) {
    // Imprimir el valor en formato binario
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        int bit = (decimal >> i) & 1;
        printf("%d", bit);
    }
}
int main() {
    printf("%-10s %-10s %-10s %-10s\n", "Decimal", "Binario", "Octal", "Hexadecimal");
    for (int decimal = 1; decimal <= 256; decimal++) {
        imprimirBinario(decimal);
        printf("%-10d %-10u %-10o %-10x\n", decimal, decimal, decimal, decimal);
    }
    return 0;
}
