#include <stdio.h>

// Constantes do tabuleiro
#define TAM_TAB 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5  // Tamanho das matrizes de habilidade

int main() {
    
    // Header
    printf("=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n\n");

    // Construção do tabuleiro
    char coluna[TAM_TAB] = {'A','B','C','D','E','F','G','H','I','J'};
    int linhas[TAM_TAB] = {1,2,3,4,5,6,7,8,9,10};
    int tabuleiro[TAM_TAB][TAM_TAB] = {AGUA};

    // Posicionando navios
    for(int i = 6; i < 6 + 3; i++) tabuleiro[i][3] = NAVIO; // Vertical
    for(int i = 5; i < 5 + 3; i++) tabuleiro[5][i] = NAVIO; // Horizontal
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = NAVIO; // Diagonal

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Matriz do Cone
    for(int i = 0; i < TAM_HAB; i++) {
        for(int j = 0; j < TAM_HAB; j++) {
            if(j >= i/2 && j < TAM_HAB - i/2 && i <= TAM_HAB/2 + 1)
                cone[i][j] = 1;
        }
    }

    // Matriz da Cruz
    for(int i = 0; i < TAM_HAB; i++) {
        for(int j = 0; j < TAM_HAB; j++) {
            if(i == TAM_HAB/2 || j == TAM_HAB/2)
                cruz[i][j] = 1;
        }
    }

    // Matriz do Octaedro
    for(int i = 0; i < TAM_HAB; i++) {
        for(int j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2);
            if(dist <= TAM_HAB/2)
                octaedro[i][j] = 1;
        }
    }

    // Aplicando habilidades ao tabuleiro
    for(int i = 0; i < TAM_HAB; i++) {
        for(int j = 0; j < TAM_HAB; j++) {
            int x = 2 + i - TAM_HAB/2;
            int y = 2 + j - TAM_HAB/2;
            if(x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB && cone[i][j] == 1)
                tabuleiro[x][y] = HABILIDADE;
        }
    }

    // Exibindo o tabuleiro
    printf("   ");
    for(int i = 0; i < TAM_TAB; i++) printf("%c  ", coluna[i]);
    printf("\n");

    for(int j = 0; j < TAM_TAB; j++) {
        printf("%2d", linhas[j]);
        for(int i = 0; i < TAM_TAB; i++) {
            printf(" %d ", tabuleiro[j][i]);
        }
        printf("\n");
    }

    // Footer
    printf("\n=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n");

    return 0;
}