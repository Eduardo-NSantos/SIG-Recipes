#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 30

// Retirado de https://www.quora.com/How-do-I-clear-the-buffer-in-C (11/11/2024)
void clear(void) { // Limpa Buffer
    while (getchar() != '\n');
}

char* input(void) {
    char linha[256];
    char* variavel;

    fgets(linha, 255, stdin);
    int tamanho = strlen(linha);

    // Trecho adaptado do ChatGPT para remover o \n do final da String
    if (linha[tamanho - 1] == '\n') {
        linha[tamanho - 1] = '\0';
        tamanho--;
    }

    variavel = (char*) malloc(tamanho+1);
    strcpy(variavel, linha);

    return variavel;
}

int ehDigito(char* variavel) {
    for (int i = 0; i < strlen(variavel); i++) {
        if (variavel[i] < '0' || variavel[i] > '9') {
            return 0;
        }
    }

    return 1;
}

int valida_email(char *email){
    char c;
    int tamanho = strlen(email);
    int cont_arroba = 0;
    int posicao_do_arroba;

    if(tamanho > 50){
        return 0;
    }
    for(int i = 0; i < tamanho; i++){
        c = email[i];
        if(c == '@'){
            cont_arroba++;
            posicao_do_arroba = i;
        }else if(!(isalnum(c) || c == '.' || c == '_' || c == '-')){
            return 0;
        }
    }
    if(cont_arroba != 1){
        return 0;
    }
    if(!(posicao_do_arroba < tamanho - 1)){ //se não tiver algo após o arroba, a função retorna 0
        return 0;
    }
    return 1;
}

int valida_nome(char *nome){
    char c;
    char tamanho = strlen(nome);

    if(tamanho > 50){
        return 0;
    }
    for(int i = 0; i < tamanho; i++){
        c = nome[i];
        if(!(isalpha(c) || c == ' ' || c == '.' || c == '-')){
            return 0;
        }
    }
    return 1;
}

int valida_senha(char *senha){
    char c;
    int tamanho = strlen(senha);

    if(tamanho > 24){
        return 0;
    }
    for(int i = 0; i < tamanho; i++){
        c = senha[i];
        if(c == '"' || c == ' '){
            return 0;
        }
    }
    return 1;
}

int valida_receita(char *receita){
    int tamanho = strlen(receita);

    if (tamanho > 50){
        return 0;
    }
    return 1;
}

int valida_descricao(char *descricao){
    int tamanho = strlen(descricao);

    if (tamanho > 255){
        return 0;
    }
    return 1;
}

int valida_tamanho(char *tamanho) {
    int int_tam = atoi(tamanho);

    if (!ehDigito(tamanho)) {
        return 0;
    }

    if (int_tam <= 0 || int_tam > 30) {
        return 0;
    }

    return 1;
}

void valida_ingredientes(char** array_ingredientes, int tamanho){
    char* ingrediente;
    int tamanho_palavra;

    for(int i = 0; i < tamanho; i++){
        printf("%d: ", i + 1);
        ingrediente = input();
        tamanho_palavra = strlen(ingrediente) + 1;
        array_ingredientes[i] = (char*) malloc(tamanho_palavra * sizeof(char));
        strcpy(array_ingredientes[i], ingrediente);
    }
}

void valida_materiais(char** array_materiais, int tamanho){
    char* material;
    int tamanho_palavra;

    for(int i = 0; i < tamanho; i++){
        printf("%d: ", i + 1);
        material = input();
        tamanho_palavra = strlen(material);
        array_materiais[i] = (char*) malloc(tamanho_palavra * sizeof(char*));
        strcpy(array_materiais[i], material);
    }
}

int valida_tempo(char *tempo) {
    int tamanho = strlen(tempo);

    if (tamanho != 5) {
        return 0;
    }

    if (tempo[2] != ':') {
        return 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (i != 2 && !isdigit(tempo[i])) {
            return 0;
        }
    }

    return 1;
}

int valida_complexidade(char *complex) {
    int tamanho = strlen(complex);
    int n = *complex - '0';

    if (tamanho != 1 || !ehDigito(complex)) {
        return 0;
    } else if (n < 1 || n > 5) {
        return 0;
    }

    return 1;
}

int valida_modo(char *modo) {
    int tamanho = strlen(modo);

    if (tamanho > 255){
        return 0;
    }
    return 1;
}
