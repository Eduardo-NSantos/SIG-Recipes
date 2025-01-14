#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lista_ingredientes(char* arquivo, char* ingrediente) {
    FILE *fp;
    char letra;
    char* texto;
    int tam;
    int i;
    int linhas;
    char ing[51];

    fp = fopen(arquivo, "rt");
    if (fp == NULL){
        printf("Erro na leitura do arquivo\n!");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);   //Manda o cursor para o fim do arquivo
    tam = ftell(fp);          //A posição final é igual ao tamanho do arquivo
    rewind(fp);               //Volta para o início do arquivo

    linhas = 0;
    letra = fgetc(fp);
    while (letra != EOF) {    // Conta quantas linhas tem no arquivo
        if (letra == '\n') {
            linhas++;
        }
        letra = fgetc(fp);
    }

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
    
    printf("%p\n\n", strstr(texto, ingrediente));

    if (strstr(texto, ingrediente) != NULL) {
        return texto;
    } else {
        return NULL;
    }


    return NULL;
}

//Feita por Flávius Gorgônio