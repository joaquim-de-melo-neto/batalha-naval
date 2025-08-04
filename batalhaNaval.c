#include <stdio.h>

// Desafio Batalha Naval - Nivel Mestre
#define LINHA 5
#define COLUNA 5

// Constantes para o tabuleiro
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

// Função para aplicar habilidades no tabuleiro

void aplicarHabilidades(int tabuleiro[10][10], int habilidade[LINHA][COLUNA], int origemLinha, int origemColuna)
{
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            int linhatabuleiro = origemLinha + i - LINHA / 2;
            int colunatabuleiro = origemColuna + j - COLUNA / 2;

            if (linhatabuleiro >= 0 && linhatabuleiro < 10 &&
                colunatabuleiro >= 0 && colunatabuleiro < 10)
            {
                if (habilidade[i][j] == 1)
                {
                    tabuleiro[linhatabuleiro][colunatabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

int main()
{
    // Declarando uma matriz de tamanho fixo 10x10
    int tabuleiro[10][10];
    int linha, coluna;

    // Inicializando o tabuleiro com água (0)
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = AGUA;
        }

        printf("\n");
    }

    // Tamanho fixo dos navios
    int TamanhoNavio = 3;

    // 2. Posicionar navios - coordenadas iniciais
    int linhaH1 = 2, colunaH1 = 1; // Navio horizontal 1
    int linhaH2 = 4, colunaH2 = 6; // Navio horinzontal 2
    int linhaD1 = 3, colunaD1 = 0; // Navio diagonal principal
    int linhaD2 = 0, colunaD2 = 9; // Navio diagonal secundário

    // === POSICIONAR NAVIOS HORIZONTAIS ===

    // Verifica se cabe no tabuleiro e não há sobreposição - navio horizontal 1
    if (colunaH1 + TamanhoNavio <= 10)
    {
        int sobreposicao = 0;
        for (int i = 0; i < TamanhoNavio; i++)
        {
            if (tabuleiro[linhaH1][colunaH1 + i] == NAVIO)
                sobreposicao = 1;
        }

        if (!sobreposicao)
        {
            for (int i = 0; i < TamanhoNavio; i++)
            {
                tabuleiro[linhaH1][colunaH1 + i] = NAVIO;
            }
        }
        else
        {
            printf("Sobreposição detectada no navio horizontal 1!\n");
        }
    }
    else
    {
        printf("Navio horizontal 1 fora dos limites do tabuleiro!\n");
    }

    // Verifica se cabe no tabuleiro e não há sobreposição - navio horizontal 2
    if (colunaH2 + TamanhoNavio <= 10)
    {
        int sobreposicao = 0;
        for (int i = 0; i < TamanhoNavio; i++)
        {
            if (tabuleiro[linhaH2][colunaH2 + i] == NAVIO)
                sobreposicao = 1;
        }

        if (!sobreposicao)
        {
            for (int i = 0; i < TamanhoNavio; i++)
            {
                tabuleiro[linhaH2][colunaH2 + i] = NAVIO;
            }
        }
        else
        {
            printf("Sobreposição detectada no navio horizontal 2!\n");
        }
    }
    else
    {
        printf("Navio horizontal 2 fora dos limites do tabuleiro!\n");
    }

    // === POSICIONAR NAVIOS DIAGONAIS ===

    // Diagonal principal
    if (linhaD1 + TamanhoNavio <= 10 && colunaD1 + TamanhoNavio <= 10)
    {
        int sobreposicao = 0;
        for (int i = 0; i < TamanhoNavio; i++)
        {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao)
        {
            for (int i = 0; i < TamanhoNavio; i++)
            {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
        else
        {
            printf("Sobreposição detectada no navio diagonal 1!\n");
        }
    }
    else
    {
        printf("Navio diagonal 1 fora dos limites do tabuleiro!\n");
    }

    // Diagonal secundária
    if (linhaD2 + TamanhoNavio <= 10 && colunaD2 - (TamanhoNavio - 1) >= 0)
    {
        int sobreposicao = 0;
        for (int i = 0; i < TamanhoNavio; i++)
        {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao)
        {
            for (int i = 0; i < TamanhoNavio; i++)
            {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
        else
        {
            printf("Sobreposição detectada no navio diagonal 2!\n");
        }
    }
    else
    {
        printf("Navio diagonal 2 fora dos limites do tabuleiro!\n");
    }

    // Declaração das matrizes de habilidades

    int cone[LINHA][COLUNA] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    int cruz[LINHA][COLUNA] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};

    int octaedro[LINHA][COLUNA] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    // Pontos de origem (linha, coluna) para cada habilidade
    aplicarHabilidades(tabuleiro, cone, 2, 5);
    aplicarHabilidades(tabuleiro, cruz, 6, 6);
    aplicarHabilidades(tabuleiro, octaedro, 7, 2);

    // Exibindo o tabuleiro

    printf("\n==== Tabuleiro da Batalha Naval ====\n\n");

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (tabuleiro[linha][coluna] == AGUA)
            {
                printf("%d ", AGUA);
            }
            else if (tabuleiro[linha][coluna] == NAVIO)
            {
                printf("%d ", NAVIO);
            }
            else
                {
                    printf("%d ", HABILIDADE);
                }
        }

        printf("\n");
    }

    return 0;
}
