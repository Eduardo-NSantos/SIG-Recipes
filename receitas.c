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
#include "receitas.h"



//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//


void modulo_receitas(void) {
    char opcao;

    do {
        opcao = menu_receitas();
        switch (opcao) {
            case '1':
                ver_receitas();
                expandir_receita();
                break;
            case '2':
                ver_receitas();
                expandir_receita();
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
void ver_receitas(void) {
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
    printf("//                         (* 1 *) Receita 1                                  //\n");
    printf("//                         (* 2 *) Receita 2                                  //\n");
    printf("//                         (* 3 *) Receita 3                                  //\n");
    printf("//                         (* 0 *) Retornar                                   //\n");
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
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}



// --== * Mostra detalhes da receita * ==-- //
void expandir_receita() {
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         --== Nome da Receita ==--                          //\n");
    printf("//                            --== Cozinheiro ==--                            //\n");
    printf("//                         --== Data de Cadastro ==--                         //\n");
    printf("//                         --== Tempo de Preparo ==--                         //\n");
    printf("//                           --== Complexidade ==--                           //\n");
    printf("//                                                                            //\n");
    printf("//                                 Descrição                                  //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                ---=== * Ingredientes / Materiais * ===---                  //\n");
    printf("//                                                                            //\n");
    printf("//                            -= Ingrediente 1 =-                             //\n");
    printf("//                            -= Ingrediente 2 =-                             //\n");
    printf("//                            -= Ingrediente 3 =-                             //\n");
    printf("//                                                                            //\n");
    printf("//                              -= Material 1 =-                              //\n");
    printf("//                              -= Material 1 =-                              //\n");
    printf("//                              -= Material 1 =-                              //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                     ---=== * Modo de Preparo * ===---                      //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}