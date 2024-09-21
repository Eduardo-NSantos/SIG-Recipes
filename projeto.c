//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                Universidade Federal do Rio Grande do Norte                 //
//                         Disciplina de Programação                          //
//                          Prof, Flavius Gorgônio                            //
//                      Moisés Lucena, Isaque Guimarães                       //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                Versão 0.1                                  //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//

#include <stdio.h>

// --== * Assinaturas * ==-- //
void menu_principal(void);
void menu_informacoes(void);
void menu_equipe(void);
//       --== ** ==--        //


//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//



// --== * Função Principal * ==-- //
int main(void) {
    menu_principal();
    menu_informacoes();
    menu_equipe();

    return 0;
}



// --== * Funções de Cor * ==-- //
// Retiradas de: https://www.theurbanpenguin.com/4184-2/
void yellow() {
    printf("\033[0;33m");
}

void green() {
    printf("\033[0;32m");
}

void reset_color() { 
    printf("\033[0m");
}



// --== * Tela Principal * ==-- //
void menu_principal(void) {
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Menu Principal * ==---                       //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---=== * Menu Cozinheiros *  ===---                    //\n");
    printf("//             (* 2 *) ---===   * Menu Usuários *   ===---                    //\n");
    printf("//             (* 3 *) ---===   * Menu Receitas *   ===---                    //\n");
    printf("//             (* 4 *) ---===    * Informações *    ===---                    //\n");
    printf("//             (* 0 *) ---===       * Sair *        ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("\n");
    reset_color();
}



// --== * Tela de Informações * ==-- //
void menu_informacoes(void) {
    green();
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
    printf("\n");
    reset_color();
}



// --== * Informações sobre a Equipe * ==-- //
void menu_equipe(void) {
    green();
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
    printf("//                 ---=== moises.lucena.713@ufrn.edu.br ===---                //\n");
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
    printf("\n");
    reset_color();
}