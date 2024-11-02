#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 30

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

int valida_ingredientes(char *ingrediente, int *tam) {
    int tamanho_s = strlen(ingrediente);
    int tamanho_v = *tam;

    if (tamanho_s > max || tamanho_v > max) {
        return 0;
    }

    return 1;
}

int valida_materiais(char *material, int *tam) {
    int tamanho_s = strlen(material);
    int tamanho_v = *tam;

    if (tamanho_s > max || tamanho_v > max) {
        return 0;
    }

    return 1;
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

    if (tamanho != 1 || !isdigit(complex[0])) {
        return 0;
    }

    if (n < 1 || n > 5) {
        return 0;
    }

    return 1;
}