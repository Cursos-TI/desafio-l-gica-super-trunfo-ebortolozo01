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
    
    // Validação do estado (A-H)
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &c->estado);
        c->estado = toupper(c->estado);
    } while(c->estado < 'A' || c->estado > 'H');

    // Validação do código
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

    // Cálculos automáticos
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000) / c->populacao; // em milhões/hab
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

void compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    bool c1_vence = false;
    bool empate = false;
    char *nomeAtributo;
    
    switch(atributo) {
        case 1: // População
            c1_vence = c1.populacao > c2.populacao;
            empate = c1.populacao == c2.populacao;
            nomeAtributo = "População";
            break;
            
        case 2: // Área
            c1_vence = c1.area > c2.area;
            empate = c1.area == c2.area;
            nomeAtributo = "Área";
            break;
            
        case 3: // PIB
            c1_vence = c1.pib > c2.pib;
            empate = c1.pib == c2.pib;
            nomeAtributo = "PIB";
            break;
            
        case 4: // Pontos Turísticos
            c1_vence = c1.pontosTuristicos > c2.pontosTuristicos;
            empate = c1.pontosTuristicos == c2.pontosTuristicos;
            nomeAtributo = "Pontos Turísticos";
            break;
            
        case 5: // Densidade (menor vence)
            c1_vence = c1.densidadePopulacional < c2.densidadePopulacional;
            empate = c1.densidadePopulacional == c2.densidadePopulacional;
            nomeAtributo = "Densidade Populacional";
            break;
            
        case 6: // PIB per capita
            c1_vence = c1.pibPerCapita > c2.pibPerCapita;
            empate = c1.pibPerCapita == c2.pibPerCapita;
            nomeAtributo = "PIB per capita";
            break;
            
        default:
            printf("Atributo inválido!\n");
            return;
    }
    
    printf("\n--- Resultado ---\n");
    printf("Atributo comparado: %s\n", nomeAtributo);
    
    if(empate) {
        printf("Empate entre %s e %s!\n", c1.nomeCidade, c2.nomeCidade);
    } else if(c1_vence) {
        printf("Vencedor: %s (%s)\n", c1.nomeCidade, c1.codigo);
    } else {
        printf("Vencedor: %s (%s)\n", c2.nomeCidade, c2.codigo);
    }
}

void menuComparacao(struct Carta c1, struct Carta c2) {
    int opcao;
    bool sair = false;
    
    while(!sair) {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("1. Comparar por População\n");
        printf("2. Comparar por Área\n");
        printf("3. Comparar por PIB\n");
        printf("4. Comparar por Pontos Turísticos\n");
        printf("5. Comparar por Densidade Populacional\n");
        printf("6. Comparar por PIB per capita\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                compararAtributo(c1, c2, opcao);
                break;
                
            case 0:
                sair = true;
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    }
}

int main() {
    struct Carta cartas[MAX_CARTAS];
    
    // Cadastro das cartas
    for(int i = 0; i < MAX_CARTAS; i++) {
        cadastrarCarta(&cartas[i], i+1);
    }
    
    // Exibição das cartas
    for(int i = 0; i < MAX_CARTAS; i++) {
        exibirCarta(cartas[i], i+1);
    }
    
    // Menu de comparação
    menuComparacao(cartas[0], cartas[1]);
    
    return 0;
}