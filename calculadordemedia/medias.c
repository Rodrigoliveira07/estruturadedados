#include <stdio.h>
#include <string.h>

void swap(char *arr[], int i, int j) {
    char temp[50];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quicksort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps = 0;
    int comparisons = 0;

    quicksort(arr, 0, n - 1);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    printf("\n");

    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s\n", arr[i]);
    }
    fclose(outputFile);

    printf("Numero de Trocas: %d\n", swaps);
    printf("Numero de Comparacoes: %d\n", comparisons);

    if (n % 2 == 0) {
        char *median1 = arr[n / 2 - 1];
        char *median2 = arr[n / 2];
        printf("Mediana: %s e %s\n", median1, median2);
    } else {
        char *median = arr[n / 2];
        printf("Mediana: %s\n", median);
    }

    return 0;
}
