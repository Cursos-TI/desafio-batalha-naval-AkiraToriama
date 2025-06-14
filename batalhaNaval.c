#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // 1 = navio, 0 = água
    int matriz[10][10] = {
        {1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}
    };
    int linha, coluna;
    int tirosRestantes = 75; // Número de tiros permitidos
    int naviosRestantes = 31; // Total de navios (soma dos 1's na matriz)

    printf("Batalha naval\n");
