//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                Universidade Federal do Rio Grande do Norte                 //
//                         Disciplina de Programação                          //
//                          Prof, Flavius Gorgônio                            //
//                      Moisés Lucena, Isaque Guimarães                       //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                Versão 0.4                                  //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cozinheiros.h"
#include "receitas.h"
#include "uteis.h"


//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//

void modulo_cozinheiro(void) {
    char opcao;

    do {
        opcao = menu_cozinheiro();
        switch (opcao) {
            case '1':
                cadastra_receita();
                break;
            case '2':
                altera_receita();
                break;
            case '3':
                deleta_receita();
                break;
            case '4':
                ver_receitas();
                expandir_receita();
                break;
        }
    } while (opcao != '0');
}



// --== * Menu do Cozinheiro * ==-- //
char menu_cozinheiro(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                      ---== * Menu Cozinheiro * ==---                       //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//           (* 1 *) ---===  * Cadastrar Receita *  ===---                    //\n");
    printf("//           (* 2 *) ---===  * Modificar Receita *  ===---                    //\n");
    printf("//           (* 3 *) ---===   * Apagar Receita *    ===---                    //\n");
    printf("//           (* 4 *) -= * Visualizar Receitas (Próprias) * =-                 //\n");
    printf("//           (* 0 *) ---===      * Retornar *      ===---                     //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}



// --== * Cadastra Receita * ==-- //
void cadastra_receita(void) {
    char* receita;
    char* descricao;
    char** ingredientes;
    char** materiais;
    char* tempo;
    char* modo;
    char* complex;

    char* quantidade_ingredientes;
    char* quantidade_materiais;

    int quantidade = 0;

    struct cozinheiro dados;

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                      ---== * Cadastrar Receita * ==---                     //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome da Receita: ");
    receita = input();
    while (!valida_receita(receita)) {
        printf("//         --== Dado inválido, digite novamente: ");
        receita = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Complexidade (1-5): ");
    complex = input();
    while (!valida_complexidade(complex)) {
        printf("//         --== Dado inválido, digite novamente: ");
        complex = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Tempo de Preparo (Formato 00:00): ");
    tempo = input();
    while (!valida_tempo(tempo)) {
        printf("//         --== Dado inválido, digite novamente: ");
        tempo = input();
    }

    printf("//                                                                            //\n"); 
    printf("//         --== Informe a quantidade de ingredientes: ");
    quantidade_ingredientes = input();
    while (!valida_tamanho(quantidade_ingredientes)) {
        printf("//         --== Valor inválido, digite novamente: ");
        quantidade_ingredientes = input();
    }
    quantidade = atoi(quantidade_ingredientes);
    ingredientes = (char**) malloc(quantidade * sizeof(char*));
    valida_ingredientes(ingredientes, quantidade);

    printf("//         --== Informe a quantidade de materiais: ");
    quantidade_materiais = input();
    while (!valida_tamanho(quantidade_materiais)) {
        printf("//         --== Valor inválido, digite novamente: ");
        quantidade_materiais = input();
    }
    quantidade = atoi(quantidade_materiais);
    materiais = (char**) malloc(quantidade * sizeof(char*));
    valida_materiais(materiais, quantidade);

    printf("//                                                                            //\n");
    printf("//                         ---== * Descricao * ==---                          //\n");
    printf("\n");
    printf("--== ");                                                 
    descricao = input();
    while (!valida_descricao(descricao)) {
        printf("--== Inválido, digite novamente: ");
        descricao = input();
    }

    printf("//                                                                            //\n"); 
    printf("//                       ---== * Modo de Preparo * ==---                      //\n");
    printf("\n");
    printf("--== ");
    modo = input();
    while (!valida_modo(modo)) {
        printf("--== Inválido, digite novamente: ");
        modo = input();
    }
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    strcpy(dados.receita, receita);
    strcpy(dados.descricao, descricao);
    strcpy(dados.tempo, tempo);
    strcpy(dados.modo, modo);
    strcpy(dados.complex, complex);

    free(receita);
    free(complex);
    free(tempo);
    free(descricao);
    free(modo);
    quantidade = atoi(quantidade_ingredientes);
    for(int i = 0; i < quantidade; i++){
        free(ingredientes[i]);
    }
    free(ingredientes);
    quantidade = atoi(quantidade_materiais);
    for(int i = 0; i < quantidade; i++){
        free(materiais[i]);
    }
    free(materiais);
    free(quantidade_ingredientes);
    free(quantidade_materiais);
}



// --== * Altera Receitas  * ==-- //
void altera_receita(void) {
    char* receita;
    char* descricao;
    char** ingredientes;
    char** materiais;
    char* tempo;
    char* modo;
    char* complex;

    char* quantidade_ingredientes;
    char* quantidade_materiais;

    int quantidade = 0;

    struct cozinheiro dados;
    
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Alterar Receita * ==---                      //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome da Receita: ");
    receita = input();
    while (!valida_receita(receita)) {
        printf("//         --== Dado inválido, digite novamente: ");
        receita = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Complexidade (1-5): ");
    complex = input();
    while (!valida_complexidade(complex)) {
        printf("//         --== Dado inválido, digite novamente: ");
        complex = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Tempo de Preparo (Formato 00:00): ");
    tempo = input();
    while (!valida_tempo(tempo)) {
        printf("//         --== Dado inválido, digite novamente: ");
        tempo = input();
    }

    printf("//                                                                            //\n"); 
    printf("//         --== Informe a quantidade de ingredientes: ");
    quantidade_ingredientes = input();
    while (!valida_tamanho(quantidade_ingredientes)) {
        printf("//         --== Valor inválido, digite novamente: ");
        quantidade_ingredientes = input();
    }
    quantidade = atoi(quantidade_ingredientes);
    ingredientes = (char**) malloc(quantidade * sizeof(char*));
    valida_ingredientes(ingredientes, quantidade);

    printf("//         --== Informe a quantidade de materiais: ");
    quantidade_materiais = input();
    while (!valida_tamanho(quantidade_materiais)) {
        printf("//         --== Valor inválido, digite novamente: ");
        quantidade_materiais = input();
    }
    quantidade = atoi(quantidade_materiais);
    materiais = (char**) malloc(quantidade * sizeof(char*));
    valida_materiais(materiais, quantidade);

    printf("//                                                                            //\n");
    printf("//                         ---== * Descricao * ==---                          //\n");
    printf("\n");
    printf("--== ");                                                 
    descricao = input();
    while (!valida_descricao(descricao)) {
        printf("--== Inválido, digite novamente: ");
        descricao = input();
    }

    printf("//                                                                            //\n"); 
    printf("//                       ---== * Modo de Preparo * ==---                      //\n");
    printf("\n");
    printf("--== ");
    modo = input();
    while (!valida_modo(modo)) {
        printf("--== Inválido, digite novamente: ");
        modo = input();
    }
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    strcpy(dados.receita, receita);
    strcpy(dados.descricao, descricao);
    //strcpy(dados.ingredientes, ingredientes);
    //strcpy(dados.materiais, materiais);
    strcpy(dados.tempo, tempo);
    strcpy(dados.modo, modo);
    strcpy(dados.complex, complex);

    free(receita);
    free(complex);
    free(tempo);
    free(descricao);
    free(modo);
    quantidade = atoi(quantidade_ingredientes);
    for(int i = 0; i < quantidade; i++){
        free(ingredientes[i]);
    }
    free(ingredientes);
    quantidade = atoi(quantidade_materiais);
    for(int i = 0; i < quantidade; i++){
        free(materiais[i]);
    }
    free(materiais);
    free(quantidade_ingredientes);
    free(quantidade_materiais);
}



// --== * Deleta Receita * ==-- //
void deleta_receita(void) {
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Deletar Receita * ==---                      //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//              ---=== Esta receita excluida permanentemente ===---           //\n");
    printf("//                                                                            //\n");
    printf("//                       ---=== Confirmar (S/N):  ===---                      //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}




