#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char curso[50];
    float nota1;
    float nota2;
} Aluno;

int main() {
    FILE *entrada, *saida;
    char linha[512];  
    
    entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    saida = fopen("SituacaoFinal.csv", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }
    
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        Aluno aluno;
        float media;
        char situacao[15];
        
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", aluno.nome, aluno.telefone, aluno.curso, &aluno.nota1, &aluno.nota2);
        
        media = (aluno.nota1 + aluno.nota2) / 2.0;
        
        if (media >= 7.0) {
            strcpy(situacao, "APROVADO");
        } else {
            strcpy(situacao, "REPROVADO");
        }
        
        fprintf(saida, "%s,%.2f,%s\n", aluno.nome, media, situacao);
    }
    
    fclose(entrada);
    fclose(saida);
    
    printf("Seus dados foram processados. Resultados salvos em SituacaoFinal.csv\n");
    
    return 0;
}