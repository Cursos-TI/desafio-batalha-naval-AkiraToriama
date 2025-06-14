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

    
    while (tirosRestantes > 0 && naviosRestantes > 0) {
        printf("Digite a linha e a coluna do tiro (0-9) ou (-1 -1) para sair:\n");
        scanf("%d %d", &linha, &coluna);

        if (linha == -1 || coluna == -1) {
            printf("Jogo encerrado pelo usuário.\n");
            break;
        }

        if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9) {
            printf("Tiro fora do tabuleiro!\n");
        } else if (matriz[linha][coluna] == 0) {
            printf("Água!\n");
            matriz[linha][coluna] = -1; // Marca como água já atingida
            tirosRestantes--;
        } else if (matriz[linha][coluna] == 1) {
            printf("Acertou um navio!\n");
            matriz[linha][coluna] = -2; // Marca navio atingido
            naviosRestantes--;
            tirosRestantes--;
        } else {
            printf("Você já atirou aqui!\n");
        }
        
        printf("Tabuleiro atualizado:\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matriz[i][j] == -1) {
                    printf("~ ");
                } else if (matriz[i][j] == -2) {
                    printf("X ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
        printf("Tiros restantes: %d | Navios restantes: %d\n", tirosRestantes, naviosRestantes);
    }

    if (naviosRestantes == 0) {
        printf("Parabéns! Você afundou todos os navios.\n");
    } else if (tirosRestantes == 0) {
        printf("Fim dos tiros! Você não afundou todos os navios.\n");
    }

    return 0;
}