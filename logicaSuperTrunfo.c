#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CARTAS 2

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

void cadastrarCarta(struct Carta *c, int num) {
    printf("\n=== Cadastro Carta %d ===\n", num);
    
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &c->estado);
        c->estado = toupper(c->estado);
    } while(c->estado < 'A' || c->estado > 'H');

    do {
        printf("Código (ex: A01): ");
        scanf("%3s", c->codigo);
    } while(!isalpha(c->codigo[0]) || !isdigit(c->codigo[1]) || !isdigit(c->codigo[2]));

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade);

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("Área (km²): ");
    scanf("%f", &c->area);

    printf("PIB (bilhões): ");
    scanf("%f", &c->pib);

    printf("Pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000) / c->populacao;
}

void exibirCarta(struct Carta c, int num) {
    printf("\n=== Carta %d ===\n", num);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f milhões/hab\n", c.pibPerCapita);
}

float obterValorAtributo(struct Carta c, int atributo) {
    switch(atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return -c.densidadePopulacional; // negativo pq menor é melhor
        case 6: return c.pibPerCapita;
        default: return -1;
    }
}

char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional (menor vence)";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

void compararDoisAtributos(struct Carta c1, struct Carta c2, int a1, int a2) {
    float valorC1_A1 = obterValorAtributo(c1, a1);
    float valorC2_A1 = obterValorAtributo(c2, a1);
    float valorC1_A2 = obterValorAtributo(c1, a2);
    float valorC2_A2 = obterValorAtributo(c2, a2);

    int pontosC1 = (valorC1_A1 > valorC2_A1 ? 1 : (valorC1_A1 == valorC2_A1 ? 0 : -1))
                 + (valorC1_A2 > valorC2_A2 ? 1 : (valorC1_A2 == valorC2_A2 ? 0 : -1));
    
    printf("\n--- Comparação ---\n");
    printf("Atributo 1: %s\n", nomeAtributo(a1));
    printf("Atributo 2: %s\n", nomeAtributo(a2));
    
    printf("%s: %.2f / %.2f\n", c1.nomeCidade, valorC1_A1, valorC1_A2);
    printf("%s: %.2f / %.2f\n", c2.nomeCidade, valorC2_A1, valorC2_A2);

    printf("\nResultado: ");
    pontosC1 > 0 ? printf("Vencedor: %s (%s)\n", c1.nomeCidade, c1.codigo) :
    pontosC1 < 0 ? printf("Vencedor: %s (%s)\n", c2.nomeCidade, c2.codigo) :
                   printf("Empate entre %s e %s!\n", c1.nomeCidade, c2.nomeCidade);
}

void menuComparacaoAvancada(struct Carta c1, struct Carta c2) {
    int opcao1, opcao2;
    char continuar;

    do {
        printf("\n=== MENU DE COMPARAÇÃO MESTRE ===\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional (menor vence)\n");
        printf("6. PIB per capita\n");

        do {
            printf("Escolha o 1º atributo (1 a 6): ");
            scanf("%d", &opcao1);
        } while(opcao1 < 1 || opcao1 > 6);

        do {
            printf("Escolha o 2º atributo (diferente do 1º): ");
            scanf("%d", &opcao2);
        } while(opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1);

        compararDoisAtributos(c1, c2, opcao1, opcao2);

        printf("\nDeseja fazer outra comparação? (s/n): ");
        scanf(" %c", &continuar);
    } while(tolower(continuar) == 's');
}

int main() {
    struct Carta cartas[MAX_CARTAS];

    for(int i = 0; i < MAX_CARTAS; i++) {
        cadastrarCarta(&cartas[i], i+1);
    }

    for(int i = 0; i < MAX_CARTAS; i++) {
        exibirCarta(cartas[i], i+1);
    }

    menuComparacaoAvancada(cartas[0], cartas[1]);

    return 0;
}
