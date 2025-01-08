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
#include "cozinheiros.h"
#include "usuario.h"
#include "uteis.h"



//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//


void modulo_receitas(void) {
    char opcao;
    int id_receita;

    do {
        opcao = menu_receitas();
        switch (opcao) {
            case '1':
                id_receita = ver_receitas();
                expandir_receita(id_receita);
                break;
            case '2':
                id_receita = ver_receitas();
                expandir_receita(id_receita);
                break;
        }
    } while (opcao != '0');
}


// --== * Menu de Receitas  * ==-- //
char menu_receitas(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         - --== * Receitas * ==---                          //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) --== * Ver Receitas (Todas) * ==--                     //\n");
    printf("//             (* 2 *) --==  * Receitas Favoritas *  ==--                     //\n");
    printf("//             (* 0 *) ---===     * Retornar *     ===---                     //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
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
    for (int i = 0; i < tamanhoarray; i++) {
        printf("//    (* %d *) %s\n", i+1, v_receitas[i]->receita);    
    }
    printf("//                                                                            //\n");
    printf("//    (* 0 *) Retornar                                                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---=== * Filtrar por * ===---                       //\n");
    printf("//                                                                            //\n");
    printf("//                            --= ( * Nome * ) =--                            //\n");
    printf("//                            --= ( * Data * ) =--                            //\n");
    printf("//                        --= ( * Ingredientes * ) =--                        //\n");
    printf("//                        --= ( * Complexidade * ) =--                        //\n");
    printf("//                         --= ( * Favoritos * ) =--                          //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Digite o ID da receita: ");
    scanf(" %d", &opcao);
    getchar();

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