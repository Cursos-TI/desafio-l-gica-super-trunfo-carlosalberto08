#include <stdio.h>

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    // Leitura dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (A a H): ");
    scanf(" %c", &estado1);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^"]);
    printf("Digite a População:"", nomeCidade1);");
    scanf("%d", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Leitura dos dados da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (A a H): ");
    scanf(" %c", &estado2);
    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^"]", nomeCidade2");
    printf("Digite a População: ");
    scanf("%d", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados
    printf("\n--- Cartas Cadastradas ---\n");
    printf("%s (Estado %c)\n", nomeCidade1, estado1);
    printf("%s (Estado %c)\n", nomeCidade2, estado2);

    // Menu interativo para escolha dos atributos
    int escolha1, escolha2;
    float valor1_carta1, valor2_carta1, valor1_carta2, valor2_carta2;
    float soma1, soma2;

    printf("\nAtributos:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &escolha1);

    // Menu dinâmico: evita repetir o mesmo atributo
    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &escolha2);
        if (escolha2 == escolha1)
            printf("Os atributos devem ser diferentes!\n");
    } while (escolha2 == escolha1);

    // Função auxiliar para obter valor do atributo
    float getValor(int escolha, int carta) {
        switch (escolha) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontosTuristicos1 : pontosTuristicos2;
            case 5: return carta == 1 ? densidade1 : densidade2;
            case 6: return carta == 1 ? pibPerCapita1 : pibPerCapita2;
            default: return 0;
        }
    }

    valor1_carta1 = getValor(escolha1, 1);
    valor2_carta1 = getValor(escolha2, 1);
    valor1_carta2 = getValor(escolha1, 2);
    valor2_carta2 = getValor(escolha2, 2);

    // Lógica de comparação com regra invertida para densidade
    float pontos1 = 0, pontos2 = 0;
    pontos1 += (escolha1 == 5) ? (valor1_carta1 < valor1_carta2 ? 1 : 0) : (valor1_carta1 > valor1_carta2 ? 1 : 0);
    pontos2 += (escolha1 == 5) ? (valor1_carta2 < valor1_carta1 ? 1 : 0) : (valor1_carta2 > valor1_carta1 ? 1 : 0);
    pontos1 += (escolha2 == 5) ? (valor2_carta1 < valor2_carta2 ? 1 : 0) : (valor2_carta1 > valor2_carta2 ? 1 : 0);
    pontos2 += (escolha2 == 5) ? (valor2_carta2 < valor2_carta1 ? 1 : 0) : (valor2_carta2 > valor2_carta1 ? 1 : 0);

    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    // Exibição dos resultados
    printf("\nComparando atributos %d e %d:\n", escolha1, escolha2);
    printf("%s - %.2f e %.2f (Soma: %.2f)\n", nomeCidade1, valor1_carta1, valor2_carta1, soma1);
    printf("%s - %.2f e %.2f (Soma: %.2f)\n", nomeCidade2, valor1_carta2, valor2_carta2, soma2);

    (soma1 > soma2) ? printf("\n%s venceu!\n", nomeCidade1) :
    (soma2 > soma1) ? printf("\n%s venceu!\n", nomeCidade2) :
                      printf("\nEmpate!\n");

    return 0;
}
