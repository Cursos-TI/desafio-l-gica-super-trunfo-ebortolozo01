#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, int numeroCarta) {
    printf("\n=== Cadastro da Carta %d ===\n", numeroCarta);
    
    // Estado (A-H)
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &carta->estado);
        carta->estado = toupper(carta->estado);
    } while (carta->estado < 'A' || carta->estado > 'H');

    // Código (A01, B02, etc.)
    do {
        printf("Código (Ex: A01): ");
        scanf("%s", carta->codigo);
    } while (strlen(carta->codigo) != 3 || !isalpha(carta->codigo[0]) || !isdigit(carta->codigo[1]) || !isdigit(carta->codigo[2]));

    // Nome da cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta->nomeCidade);

    // População
    printf("População: ");
    scanf("%lu", &carta->populacao);

    // Área
    printf("Área (km²): ");
    scanf("%f", &carta->area);

    // PIB
    printf("PIB (bilhões de reais): ");
    scanf("%f", &carta->pib);

    // Pontos turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;
}

// Função para exibir uma carta
void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("\n=== Carta %d ===\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
}

// Função para comparar cartas
void compararCartas(struct Carta carta1, struct Carta carta2) {
    int atributo;
    
    printf("\n=== Comparação de Cartas ===\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Opção: ");
    scanf("%d", &atributo);

    printf("\nResultado da comparação:\n");
    
    if (atributo == 1) {
        // Comparação por população
        if (carta1.populacao > carta2.populacao) {
            printf("Carta 1 (%s) vence em População!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Carta 2 (%s) vence em População!\n", carta2.nomeCidade);
        } else {
            printf("Empate em População!\n");
        }
    } 
    else if (atributo == 2) {
        // Comparação por área
        if (carta1.area > carta2.area) {
            printf("Carta 1 (%s) vence em Área!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Carta 2 (%s) vence em Área!\n", carta2.nomeCidade);
        } else {
            printf("Empate em Área!\n");
        }
    }
    else if (atributo == 3) {
        // Comparação por PIB
        if (carta1.pib > carta2.pib) {
            printf("Carta 1 (%s) vence em PIB!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Carta 2 (%s) vence em PIB!\n", carta2.nomeCidade);
        } else {
            printf("Empate em PIB!\n");
        }
    }
    else if (atributo == 4) {
        // Comparação por pontos turísticos
        if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
            printf("Carta 1 (%s) vence em Pontos Turísticos!\n", carta1.nomeCidade);
        } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
            printf("Carta 2 (%s) vence em Pontos Turísticos!\n", carta2.nomeCidade);
        } else {
            printf("Empate em Pontos Turísticos!\n");
        }
    }
    else if (atributo == 5) {
        // Comparação por densidade populacional (menor vence)
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Carta 1 (%s) vence em Densidade Populacional!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Carta 2 (%s) vence em Densidade Populacional!\n", carta2.nomeCidade);
        } else {
            printf("Empate em Densidade Populacional!\n");
        }
    }
    else {
        printf("Atributo inválido!\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparação das cartas
    compararCartas(carta1, carta2);

    return 0;
}