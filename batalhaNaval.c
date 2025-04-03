#include <stdio.h>

int main() {
    
    //Header
    printf("=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n\n");

    //Construindo as colunas do jogo
    char coluna [10] = {'A','B','C','D','E','F','G','H','I','J'};
    //Construindo as linhas do jogo 
    int linhas [10] = {1,2,3,4,5,6,7,8,9,10};
    //Construindo o tabuleiro do jogo
    int tabuleiro [10][10] = {0};

    //posição do navio 1
        for(int i = 6; i < 9; i++){
        tabuleiro[i][3] = 3;
    }

    //posição do navio 2
        for(int i = 5; i < 8; i++){
        tabuleiro [5][i] = 3;
    }

    // coluna da variavel I
    printf("   ");//Alinha as colunas
        for (int i = 0; i < 10; i++)
    {
        printf("%c  ", coluna[i]);
    }
        printf("\n");

    // linha da variavel J
        for (int j = 0; j < 10; j++)
    {
        printf("%2d", linhas[j]);
        for (int i = 0; i < 10; i++)
        {
            printf(" %d ", tabuleiro[j][i]);
        }
        printf("\n");
    }

    //Footer
    printf("\n=====================================\n");
    printf("==========| BATALHA NAVAL |==========\n");
    printf("=====================================\n");

    return 0;
}
