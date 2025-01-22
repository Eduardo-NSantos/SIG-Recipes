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
#include "receitas.h"
#include "usuario.h"
#include "uteis.h"

typedef struct receita Rec;


//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//

void modulo_cozinheiro(int id_usuario) {
    char opcao;
    int id_receita;

    do {
        opcao = menu_cozinheiro();
        switch (opcao) {
            case '1':
                cadastra_receita(id_usuario);
                break;
            case '2':
                altera_receita();
                break;
            case '3':
                deleta_receita();
                break;
            case '4':
                id_receita = ver_receitas();
                if(id_receita == 0){
                    break;
                }
                expandir_receita(id_receita);
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
    printf("//           (* 1 *) ---===  *  Cadastrar Receita  *  ===---                  //\n");
    printf("//           (* 2 *) ---===  *  Modificar Receita  *  ===---                  //\n");
    printf("//           (* 3 *) ---===  *    Apagar Receita   *  ===---                  //\n");
    printf("//           (* 4 *) ---===  * Visualizar Receitas *  ===---                  //\n");
    printf("//           (* 0 *) ---===  *       Retornar      *  ===---                  //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}



// --== * Cadastra Receita * ==-- //
void cadastra_receita(int id_cozinheiro) {
    char* receita;
    char* descricao;
    char* ingredientes;
    char* materiais;
    char* tempo;
    char* modo;
    char* complex;

    Rec* rec;
    rec = (Rec*) malloc(sizeof(Rec));

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
    printf("//         --== Ingredientes: ");
    ingredientes = input();
    while (!valida_ingredientes(ingredientes)) {
        printf("//         --== Valor inválido, digite novamente: ");
        ingredientes = input();
    }

    printf("//         --== Materiais: ");
    materiais = input();
    while (!valida_materiais(materiais)) {
        printf("//         --== Valor inválido, digite novamente: ");
        materiais = input();
    }

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

    preencheReceita(id_cozinheiro, receita, descricao, ingredientes, materiais, tempo, modo, complex, rec);
    gravacao_receita("receitas.dat", rec);

    free(receita);
    free(complex);
    free(ingredientes);
    free(materiais);
    free(tempo);
    free(descricao);
    free(modo);
    free(rec);
}



// --== * Altera Receitas  * ==-- //
void altera_receita(void) {
    char* receita;
    char* descricao;
    char* ingredientes;
    char* materiais;
    char* tempo;
    char* modo;
    char* complex;

    Rec* dados;
    dados = (Rec*) malloc(sizeof(Rec));
    
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
    printf("//         --== Ingredientes: ");
    ingredientes = input();
    while (!valida_ingredientes(ingredientes)) {
        printf("//         --== Valor inválido, digite novamente: ");
        ingredientes = input();
    }

    printf("//         --== Materiais: ");
    materiais = input();
    while (!valida_materiais(materiais)) {
        printf("//         --== Valor inválido, digite novamente: ");
        materiais = input();
    }

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

    preencheReceita(0, receita, descricao, ingredientes, materiais, tempo, modo, complex, dados);

    free(receita);
    free(complex);
    free(ingredientes);
    free(materiais);
    free(tempo);
    free(descricao);
    free(modo);
    free(dados);
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

// --== * Visualiza Receitas * ==-- //
int ver_receitas(void) {
    Rec** v_receitas;
    int opcao;
    int tamanhoarray = contaReceitas("receitas.dat");

    v_receitas = listaReceitas();

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---=== * Receitas * ===---                          //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    if(tamanhoarray <= 0) {
        printf("//    Nenhuma receita cadastrada                                              //\n");
    } else {
        for (int i = 0; i < tamanhoarray; i++) {
            printf("//    (* %d *) %s\n", i+1, v_receitas[i]->receita);    
        }
    }
    printf("//                                                                            //\n");
    printf("//    (* 0 *) Retornar                                                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Digite o ID da receita: ");
    scanf(" %d", &opcao);
    getchar();

    while(opcao < 0 || opcao > tamanhoarray){
        printf("         --== ID inválido, tente novamente: ");
        scanf(" %d", &opcao);
        getchar();
    }

    for (int i = 0; i < tamanhoarray; i++) {
        free(v_receitas[i]);
    }
    free(v_receitas);

    return opcao;
}

// --== * Mostra detalhes da receita * ==-- //
void expandir_receita(int id) {
    Rec* receita = buscaReceita(id);
    Usuario* usuario = buscaUsuario(receita->id_cozinheiro); 

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//    --== %s\n", receita->receita);
    printf("//    --== Cozinheiro: %s\n", usuario->nome);
    printf("//    --== Tempo: %s\n", receita->tempo);
    printf("//    --== Complexidade: %s Estrela(s)\n", receita->complex);
    printf("//                                                                            //\n");
    printf("--== Ingredientes: %s\n", receita->ingredientes);
    printf("--== Materiais: %s\n", receita->materiais);
    printf("--== Descrição: %s\n", receita->descricao);
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("--== Modo de Preparo: %s\n", receita->modo);
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    free(receita);
}


