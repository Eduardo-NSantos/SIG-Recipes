#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lista_ingredientes(char arq[25]) {
    FILE *fp;
    char letra;
    char* texto;
    int tam;
    int i;
    int linhas;
    char ing[51];

    printf("Exemplo de Leitura de Arquivos Texto\n");
    fp = fopen("miojo_cremoso.txt", "rt");
    if (fp == NULL){
        printf("Erro na leitura do arquivo\n!");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);   //Manda o cursor para o fim do arquivo
    tam = ftell(fp);          //A posição final é igual ao tamanho do arquivo
    rewind(fp);               //Volta para o início do arquivo
    printf("O arquivo tem %d chars\n", tam);

    linhas = 0;
    letra = fgetc(fp);
    while (letra != EOF) {    // Conta quantas linhas tem no arquivo
        if (letra == '\n') {
            linhas++;
        }
        letra = fgetc(fp);
    }
    printf("O arquivo tem %d linhas\n", linhas);

    texto = (char*) malloc((tam+linhas+1)*sizeof(char));

    rewind(fp);
    i = 0;
    letra = fgetc(fp);
    while (letra != EOF) {
        texto[i] = letra;
        letra = fgetc(fp);
        i++;
    }
    texto[i]= '\0';
    fclose(fp);

    printf("Texto Lido: %d caracteres em %d linhas\n\n", i, linhas);
    printf("%s\n", texto);

    printf("Informe um ingrediente a procurar: ");
    scanf("%s", ing);
    
    printf("%p\n\n", strstr(texto, ing));

    if (strstr(texto, ing) != NULL) {
        printf("Ingrediente <%s> encontrado!\n", ing);
    } else {
        printf("Esta receita não possui <%s>.\n", ing);
    }


    return 0;
}

//Feita por Flávius Gorgônio