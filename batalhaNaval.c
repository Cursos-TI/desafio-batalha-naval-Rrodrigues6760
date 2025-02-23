#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe horizontalmente na posição especificada
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Posição inválida para o navio horizontal.\n");
        return 0;
    }
    
    // Verifica se as posições estão livres (não há sobreposição)
    for (int i = coluna; i < coluna + TAM_NAVIO; i++) {
        if (tabuleiro[linha][i] != 0) {
            printf("O navio sobrepõe outra posição.\n");
            return 0;
        }
    }

    // Posiciona o navio (valor 3 representa a parte do navio)
    for (int i = coluna; i < coluna + TAM_NAVIO; i++) {
        tabuleiro[linha][i] = 3;
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe verticalmente na posição especificada
    if (linha + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Posição inválida para o navio vertical.\n");
        return 0;
    }
    
    // Verifica se as posições estão livres (não há sobreposição)
    for (int i = linha; i < linha + TAM_NAVIO; i++) {
        if (tabuleiro[i][coluna] != 0) {
            printf("O navio sobrepõe outra posição.\n");
            return 0;
        }
    }

    // Posiciona o navio (valor 3 representa a parte do navio)
    for (int i = linha; i < linha + TAM_NAVIO; i++) {
        tabuleiro[i][coluna] = 3;
    }
    return 1;
}

int main() {
    // Inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    // Coordenadas para posicionar os navios (definidas diretamente no código)
    int linhaHorizontal = 2, colunaHorizontal = 3; // Posição do navio horizontal
    int linhaVertical = 5, colunaVertical = 6;     // Posição do navio vertical
    
    // Posiciona os navios no tabuleiro
    if (!posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        return 1;
    }
    if (!posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
