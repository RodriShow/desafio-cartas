#include <stdio.h>
#include <stdlib.h>

#define MAX_CIDADES 100

typedef struct {
    char estado[30];
    int codigo;
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaCidade;

float calcularDensidade(int populacao, float area) {
    if (area == 0) return 0;
    return populacao / area;
}

float calcularPIBPerCapita(float pib, int populacao) {
    if (populacao == 0) return 0;
    return pib / populacao;
}

void registrarCidade(CartaCidade *c) {
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Código da cidade: ");
    scanf("%d", &c->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("População: ");
    scanf("%d", &c->populacao);

    printf("PIB (em milhões R$): ");
    scanf("%f", &c->pib);

    printf("Área (km²): ");
    scanf("%f", &c->area);

    printf("Número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    c->densidadePopulacional = calcularDensidade(c->populacao, c->area);
    c->pibPerCapita = calcularPIBPerCapita(c->pib, c->populacao);
}

void exibirCidades(CartaCidade cidades[], int total) {
    printf("\n===== Cartas de Cidades Registradas =====\n");
    for (int i = 0; i < total; i++) {
        CartaCidade c = cidades[i];
        printf("\n--- Cidade %d ---\n", i + 1);
        printf("Estado: %s\n", c.estado);
        printf("Código: %d\n", c.codigo);
        printf("Nome: %s\n", c.nome);
        printf("População: %d\n", c.populacao);
        printf("PIB: R$ %.2f milhões\n", c.pib);
        printf("Área: %.2f km²\n", c.area);
        printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
        printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    }
}

int main() {
    CartaCidade cidades[MAX_CIDADES];
    int total = 0;
    char continuar;

    printf("==== Cadastro de Cartas de Cidades ====\n");

    do {
        if (total >= MAX_CIDADES) {
            printf("Limite de cidades atingido!\n");
            break;
        }

        registrarCidade(&cidades[total]);
        total++;

        printf("\nDeseja adicionar outra cidade? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    exibirCidades(cidades, total);

    return 0;
}
