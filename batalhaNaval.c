#include <stdio.h>

// Definindo as constantes
#define tamanho_do_tabuleiro 10
#define agua 0
#define navio 3
#define tamanho_do_navio 3

int main() {
    
    // Header
    printf("=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n\n");

    //Construindo as colunas do jogo
    char coluna[tamanho_do_tabuleiro] = {'A','B','C','D','E','F','G','H','I','J'};
    //Construindo as linhas do jogo 
    int linhas[tamanho_do_tabuleiro] = {1,2,3,4,5,6,7,8,9,10};
    //Construindo o tabuleiro do jogo
    int tabuleiro[tamanho_do_tabuleiro][tamanho_do_tabuleiro] = {agua};

   //posição dos navios
    for(int i = 6; i < 6 + tamanho_do_navio; i++) tabuleiro[i][3] = navio; // Vertical
    for(int i = 5; i < 5 + tamanho_do_navio; i++) tabuleiro[5][i] = navio; // Horizonta

    //posição do navio na diagonal
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = navio;

    printf("   ");
    for(int i = 0; i < tamanho_do_tabuleiro; i++) printf("%c  ", coluna[i]);
    printf("\n");

    for(int j = 0; j < tamanho_do_tabuleiro; j++){
        printf("%2d", linhas[j]);
        for(int i = 0; i < tamanho_do_tabuleiro; i++) printf(" %d ", tabuleiro[j][i]);
        printf("\n");
    }
    // Footer
    printf("\n=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n");

    return 0;
}