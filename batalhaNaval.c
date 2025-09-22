#include <stdio.h>
#include <stdlib.h> // necessário para usar abs()

#define TAM 9

// Função para exibir uma matriz
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Habilidade em forma de cone
void habilidadeCone(int matriz[TAM][TAM], int centroX, int centroY) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i >= centroX && abs(j - centroY) <= (i - centroX)) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Habilidade em forma de cruz
void habilidadeCruz(int matriz[TAM][TAM], int centroX, int centroY) {
    for (int i = 0; i < TAM; i++) {
        matriz[i][centroY] = 1;
    }
    for (int j = 0; j < TAM; j++) {
        matriz[centroX][j] = 1;
    }
}

// Habilidade em forma de octaedro
void habilidadeOctaedro(int matriz[TAM][TAM], int centroX, int centroY, int raio) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - centroX) + abs(j - centroY) <= raio) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    printf("Habilidade em cone:\n");
    habilidadeCone(tabuleiro, 2, 4);
    exibirMatriz(tabuleiro);

    // limpar matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    printf("Habilidade em cruz:\n");
    habilidadeCruz(tabuleiro, 4, 4);
    exibirMatriz(tabuleiro);

    // limpar matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    printf("Habilidade em octaedro:\n");
    habilidadeOctaedro(tabuleiro, 4, 4, 3);
    exibirMatriz(tabuleiro);

    return 0;
}