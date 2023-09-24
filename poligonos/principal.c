#include <stdio.h>
#include "ponto.h"
#include <stdlib.h>
#include <math.h>   


int main() {
    FILE *file;
    char filename[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        perror("Erro de alocacao de memoria");
        return 1;
    }

    for (int i = 0; i < numVertices; i++) {
        float x, y;
        fscanf(file, "%f %f", &x, &y);
        vertices[i] = criarPonto(x, y);
    }

    fclose(file);

    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = 0.5 * fabs(area); 

    printf("Resultado do calculo da area do poligono: %.2f\n", area);

    free(vertices);

    return 0;
}
