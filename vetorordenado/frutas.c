#include <stdio.h>
#include <string.h>

int trocas = 0;
int comparacoes = 0;

int compara(const void *a, const void *b) {
    comparacoes++;
    return strcmp(*(const char **)a, *(const char **)b);
}

void quicksort(char *arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int i = esquerda, j = direita;
        char *pivo = arr[(i + j) / 2];

        while (i <= j) {
            while (strcmp(arr[i], pivo) < 0) {
                i++;
                comparacoes++;
            }
            while (strcmp(arr[j], pivo) > 0) {
                j--;
                comparacoes++;
            }

            if (i <= j) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
                trocas++;
            }
        }

        quicksort(arr, esquerda, j);
        quicksort(arr, i, direita);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de comparacoes: %d\n", comparacoes);

    char *mediana;
    if (tamanho % 2 == 0) {
        int meio1 = tamanho / 2 - 1;
        int meio2 = tamanho / 2;
        mediana = arr[meio1];
        printf("Mediana: %s e %s\n", arr[meio1], arr[meio2]);
    } else {
        int meio = tamanho / 2;
        mediana = arr[meio];
        printf("Mediana: %s\n", arr[meio]);
    }

    FILE *arquivo_saida = fopen("frutas.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_saida, "%s\n", arr[i]);
    }

    fclose(arquivo_saida);

    return 0;
}