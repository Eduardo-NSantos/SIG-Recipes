#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "receitas.h"
#include "usuario.h"
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

int valida_ingredientes(char* ingredientes){
    int tamanho = strlen(ingredientes);

    if (tamanho > 255){
        return 0;
    }
    return 1;
}

int valida_materiais(char* materiais){
    int tamanho = strlen(materiais);

    if (tamanho > 255){
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

void preencheReceita(int id_cozinheiro, char* receita, char* descricao, char* ingredientes, char* materiais, char* tempo, char* modo, char* complex, Rec* dados) {
    if(id_cozinheiro != 0){
        dados->id_cozinheiro = id_cozinheiro;
    }
    strcpy(dados->receita, receita);
    strcpy(dados->descricao, descricao);
    strcpy(dados->ingredientes, ingredientes);
    strcpy(dados->materiais, materiais);
    strcpy(dados->tempo, tempo);
    strcpy(dados->modo, modo);
    strcpy(dados->complex, complex);
    dados->status = '1';
}

int gravacao_receita(char* arquivo, Rec* receita){
    FILE* file;
    Rec conta;
    int contador = 1;
    
    if((file = fopen(arquivo, "rb")) != NULL){
        fclose(file);
        file = fopen(arquivo, "r+b");
    }else{
        file = fopen(arquivo, "w+b");
    }

    if(file == NULL) {
        return 0;
    }

    while (fread(&conta, sizeof(Rec), 1, file)) {
        contador++;
    }

    receita->id = contador;
    
    // salva os ingredientes num arquivo txt
    char caminho[255];
    mkdir("ingredientes", 0777);
    sprintf(caminho, "ingredientes/%s.txt", receita->receita);
    FILE* arquivo_receita = fopen(caminho, "w");
    fprintf(arquivo_receita, "%s", receita->ingredientes);
    fclose(arquivo_receita);

    fwrite(receita, sizeof(Rec), 1, file);
    fclose(file);

    return 1;
}

int gravacao_usuario(char* arquivo, Usuario* usuario){
    FILE* file;
    Usuario conta;
    int contador = 1;

    if((file = fopen(arquivo, "rb")) != NULL){
        fclose(file);
        file = fopen(arquivo, "r+b");
    }else{
        file = fopen(arquivo, "w+b");
    }

    if(file == NULL) {
        return 0;
    }

    while (fread(&conta, sizeof(Usuario), 1, file) == 1) {
        contador ++;
    }

    usuario->id = contador;

    fwrite(usuario, sizeof(Usuario), 1, file);
    fclose(file);

    return 1;
}

int autentica_usuario(char* email, char* senha) {
    FILE* file;
    Usuario* usuario;
    usuario = (Usuario*) malloc(sizeof(Usuario));

    file = fopen("usuarios.dat", "rb");
    if(file == NULL) {
        return 0;
    }

    while (fread(usuario, sizeof(Usuario), 1, file)) {
        if ((strcmp(usuario->email, email) == 0) && (strcmp(usuario->senha, senha)) == 0) {
            fclose(file);
            return usuario->id;
        }
    }

    fclose(file);
    return 0;
}

int atualiza_receita(char *arquivo, int id, Rec* nova_receita){
    FILE *fp = fopen(arquivo, "rb+");
    if (fp == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    Rec receita_atual;
    while (fread(&receita_atual, sizeof(Rec), 1, fp)){
        if (receita_atual.id == id) {
            fseek(fp, -sizeof(Rec), SEEK_CUR);

            nova_receita->id = receita_atual.id;
            nova_receita->id_cozinheiro = receita_atual.id_cozinheiro;
            nova_receita->status = receita_atual.status;

            if (!fwrite(nova_receita, sizeof(Rec), 1, fp)){
                fclose(fp);
                return 0;
            }

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int atualizaUsuario(char *arquivo, int id, Usuario* novoUsuario){
    FILE *fp = fopen(arquivo, "rb+");
    if (fp == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    Usuario usuarioAtual;
    while (fread(&usuarioAtual, sizeof(Usuario), 1, fp)){
        if (usuarioAtual.id == id) {
            fseek(fp, -sizeof(Usuario), SEEK_CUR);

            novoUsuario->id = usuarioAtual.id;
            novoUsuario->status = usuarioAtual.status;
            if (!fwrite(novoUsuario, sizeof(Usuario), 1, fp)){
                fclose(fp);
                return 0;
            }

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

Usuario* buscaUsuario(int id) {
    FILE* file;
    Usuario* usuario;
    usuario = (Usuario*) malloc(sizeof(Usuario));

    file = fopen("usuarios.dat", "rb");
    if(file == NULL) {
        return 0;
    }

    while (fread(usuario, sizeof(Usuario), 1, file)) {
        if (usuario->id == id) {
            fclose(file);
            return usuario;
        }
    }

    fclose(file);
    free(usuario);

    return NULL;
}

Rec** listaReceitas(void) {
    FILE* file;
    Rec* receita;
    Rec** v_receitas;
    int tamanho = 0;
    receita = (Rec*) malloc(sizeof(Rec));

    file = fopen("receitas.dat", "rb");
    if(file == NULL) {
        return NULL;
    }

    while(fread(receita, sizeof(Rec), 1, file) == 1) { 
        tamanho++;
    }

    v_receitas = (Rec**) malloc(tamanho * sizeof(Rec*));

    fseek(file, 0, SEEK_SET); // Move o ponteiro para o início do arquivo

    for(int i = 0; i < tamanho; i++) {
        v_receitas[i] = (Rec*) malloc(sizeof(Rec));
        fread(v_receitas[i], sizeof(Rec), 1, file);
    }

    fclose(file);
    free(receita);

    return v_receitas;
}

int contaReceitas(char* arquivo) {
    FILE* file;
    Rec* receita;
    receita = (Rec*) malloc(sizeof(Rec));
    int tamanho = 0;

    file = fopen(arquivo, "rb");
    if(file == NULL) {
        return 0;
    }

    while(fread(receita, sizeof(Rec), 1, file) == 1) { 
        tamanho++;
    }

    free(receita);
    fclose(file);

    return tamanho;
}

Rec* buscaReceita(int id) {
    FILE* file;
    Rec* receita;
    receita = (Rec*) malloc(sizeof(Rec));

    file = fopen("receitas.dat", "rb");
    if(file == NULL) {
        return 0;
    }

    while (fread(receita, sizeof(Rec), 1, file)) {
        if (receita->id == id) {
            fclose(file);
            return receita;
        }
    }

    fclose(file);
    free(receita);

    return NULL;
}

int buscaStatusUsuario(int id) {
    FILE* file;
    Usuario usuario;
    int status = -1;

    file = fopen("usuarios.dat", "rb");
    if (file == NULL) {
        return -1;
    }

    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        if (usuario.id == id) {
            status = usuario.status;
            break;
        }
    }

    fclose(file);
    return status;
}