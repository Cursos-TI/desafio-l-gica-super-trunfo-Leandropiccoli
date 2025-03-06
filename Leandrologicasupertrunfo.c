#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta da cidade
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para cadastrar uma carta
void cadastrarCarta(CartaCidade *carta) {
    printf("Digite o estado: ");
    scanf(" %49[^", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\"]", carta->nome);
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaCidade carta) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

// Função para comparar duas cartas com base em um atributo
typedef enum {POPULACAO = 1, AREA, PIB, PONTOS_TURISTICOS, DENSIDADE} Atributo;

void compararCartas(CartaCidade carta1, CartaCidade carta2, Atributo atributo) {
    printf("\nComparando cartas com base em: ");
    switch (atributo) {
        case POPULACAO:
            printf("População\n");
            printf("Vencedor: %s\n", (carta1.populacao > carta2.populacao) ? carta1.nome : carta2.nome);
            break;
        case AREA:
            printf("Área\n");
            printf("Vencedor: %s\n", (carta1.area > carta2.area) ? carta1.nome : carta2.nome);
            break;
        case PIB:
            printf("PIB\n");
            printf("Vencedor: %s\n", (carta1.pib > carta2.pib) ? carta1.nome : carta2.nome);
            break;
        case PONTOS_TURISTICOS:
            printf("Pontos turísticos\n");
            printf("Vencedor: %s\n", (carta1.pontos_turisticos > carta2.pontos_turisticos) ? carta1.nome : carta2.nome);
            break;
        case DENSIDADE:
            printf("Densidade populacional\n");
            {
                float densidade1 = carta1.populacao / carta1.area;
                float densidade2 = carta2.populacao / carta2.area;
                printf("Vencedor: %s\n", (densidade1 < densidade2) ? carta1.nome : carta2.nome);
            }
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    CartaCidade carta1, carta2;
    int escolha;
    
    printf("\nCadastro da primeira cidade:\n");
    cadastrarCarta(&carta1);
    printf("\nCadastro da segunda cidade:\n");
    cadastrarCarta(&carta2);
    
    printf("\nAs cartas cadastradas são:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    do {
        printf("\nEscolha o atributo para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n6 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &escolha);
        
        if (escolha >= 1 && escolha <= 5)
            compararCartas(carta1, carta2, (Atributo)escolha);
    } while (escolha != 6);
    
    printf("Programa encerrado.\n");
    return 0;
}