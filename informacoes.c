#include <stdio.h>
#include <stdlib.h>
#include "informacoes.h"

void modulo_informacoes(void) {
    menu_informacoes();
    getchar();
    menu_equipe();
}

// --== * Tela de Informações * ==-- //
void menu_informacoes(void) {
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                   ---== * Informações Importantes * ==---                  //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//           -----===== * Caderno de Receitas Virtual * =====-----            //\n");
    printf("//                                                                            //\n");
    printf("//  Este é um sistema simples feito com intuito puramente educacional para a  //\n");
    printf("//  disciplina DCT1106 - Programação, ministrada na Universidade Federal do   //\n");
    printf("//  Rio Grande do Norte pelo professor Flavius Gorgônio. Através deste siste- //\n");
    printf("//  ma busca-se providenciar o aprendizado prático dos conceitos abordados em //\n");
    printf("//  sala de aula. O programa atua como um caderno virtual de receitas culiná- //\n");
    printf("//  rias e disponibiliza diversas funcionalidades que auxiliam tanto o usuá-  //\n");
    printf("//  rio comum em busca de receitas, quanto aqueles que buscam compartilhar    //\n");
    printf("//  suas receitas.                                                            //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}



// --== * Informações sobre a Equipe * ==-- //
void menu_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                  ---== * Equipe de Desenvolvimento * ==---                 //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         Projeto desenvolvido por:                          //\n");
    printf("//                                                                            //\n");
    printf("//                        ---=== Moisés Lucena ===---                         //\n");
    printf("//                   ---=== moisesbrats98@gmail.com ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//                                                                            //\n");
    printf("//                       ---=== Isaque Guimarães ===---                       //\n");
    printf("//                 ---=== isaqueguimaraes388@gmail.com ===---                 //\n");
    printf("//                                                                            //\n");
    printf("//                               Disponível em:                               //\n");
    printf("//             https://github.com/MoisesLuc/Projeto-Programacao.git           //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}