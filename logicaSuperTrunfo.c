#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char nomePais1[50] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1600.0;
    int pontosTuristicos1 = 100;
    float densidade1 = populacao1 / area1;

    // Dados da Carta 2
    char nomePais2[50] = "Argentina";
    int populacao2 = 45380000;
    float area2 = 2780400.0;
    float pib2 = 500.0;
    int pontosTuristicos2 = 70;
    float densidade2 = populacao2 / area2;

    int escolha;

    // Menu interativo
    printf("===== Super Trunfo de Países =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1 a 5): ");
    scanf("%d", &escolha);

    printf("\nComparando: %s vs %s\n", nomePais1, nomePais2);

    switch (escolha) {
        case 1:  // População
            printf("\nAtributo: População\n");
            printf("%s: %d habitantes\n", nomePais1, populacao1);
            printf("%s: %d habitantes\n", nomePais2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:  // Área
            printf("\nAtributo: Área\n");
            printf("%s: %.2f km²\n", nomePais1, area1);
            printf("%s: %.2f km²\n", nomePais2, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:  // PIB
            printf("\nAtributo: PIB\n");
            printf("%s: %.2f bilhões de dólares\n", nomePais1, pib1);
            printf("%s: %.2f bilhões de dólares\n", nomePais2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:  // Pontos Turísticos
            printf("\nAtributo: Pontos Turísticos\n");
            printf("%s: %d pontos turísticos\n", nomePais1, pontosTuristicos1);
            printf("%s: %d pontos turísticos\n", nomePais2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:  // Densidade Demográfica (regra invertida)
            printf("\nAtributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", nomePais1, densidade1);
            printf("%s: %.2f hab/km²\n", nomePais2, densidade2);
            if (densidade1 < densidade2) {
                printf("Resultado: %s venceu (menor densidade)!\n", nomePais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu (menor densidade)!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("\nOpção inválida! Por favor, escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}
