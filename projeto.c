//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                Universidade Federal do Rio Grande do Norte                 //
//                         Disciplina de Programação                          //
//                          Prof, Flavius Gorgônio                            //
//                      Moisés Lucena, Isaque Guimarães                       //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                Versão 0.2                                  //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//

#include <stdio.h>
#include <stdlib.h>





// --== * Assinaturas * ==-- //
void menu_principal(void);
void menu_informacoes(void);
void menu_equipe(void);
void autenticacao(void);
void login_cadastro(void);
void cadastro(void);
void menu_cozinheiros(void);
void ver_dados_coz(void);
void altera_dados_coz(void);
void deleta_conta(void);
void menu_usuarios(void);
//       --== ** ==--        //





//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//



// --== * Função Principal * ==-- //
int main(void) {
    login_cadastro();
    cadastro();
    autenticacao();
    menu_principal();
    menu_cozinheiros();
    ver_dados_coz();
    altera_dados_coz();
    deleta_conta();
    menu_usuarios();
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




// --== * Menu Principal * ==-- //
void menu_principal(void) {
    system("clear||cls");
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
    printf("                       -------======= *  * =======--------                      \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Menu dos Cozinheiros * ==-- //
void menu_cozinheiros(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         ---== * Cozinheiros * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---===       * Dados *        ===---                   //\n");
    printf("//             (* 2 *) ---===   * Alterar Dados *    ===---                   //\n");
    printf("//             (* 3 *) ---===   * Deletar Conta *    ===---                   //\n");
    printf("//             (* 0 *) ---===      * Retornar *      ===---                   //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Visualiza Dados dos Cozinheiros * ==-- //
void ver_dados_coz(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                            ---== * Dados * ==---                           //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---===       Nome        ===---                      //\n");
    printf("//                       ---===      Usuário      ===---                      //\n");
    printf("//                       ---===       Email       ===---                      //\n");
    printf("//                                                                            //\n");
    printf("//                    ---=== Informações Adicionais ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                     ----==== Lista de Receitas ====----                    //\n");
    printf("//                                                                            //\n");
    printf("//                         (* 1 *) Receita 1                                  //\n");
    printf("//                         (* 2 *) Receita 2                                  //\n");
    printf("//                         (* 3 *) Receita 3                                  //\n");
    printf("//                         (* 0 *) Retornar                                   //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Altera Dados dos Cozinheiros * ==-- //
void altera_dados_coz(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Alterar Dados * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome:                                                         //\n");
    printf("//         --== Usuário:                                                      //\n");
    printf("//         --== Email:                                                        //\n");
    printf("//         --== Senha:                                                        //\n");
    printf("//                                                                            //\n");
    printf("//         ---== Informações Adicionais (Opcional):                           //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Deletar Conta * ==-- //
void deleta_conta(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Deletar Conta * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//       ---=== Você perderá acesso a esta conta permanentemente ===---       //\n");
    printf("//                                                                            //\n");
    printf("//                      ---=== Confirmar (S/N):  ===---                       //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Menu dos Usuários * ==-- //
void menu_usuarios(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         - --== * Usuários * ==---                          //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---===       * Dados *        ===---                   //\n");
    printf("//             (* 2 *) ---===   * Alterar Dados *    ===---                   //\n");
    printf("//             (* 3 *) ---===   * Deletar Conta *    ===---                   //\n");
    printf("//             (* 4 *) ---=== * Receitas Favoritas * ===---                   //\n");
    printf("//             (* 0 *) ---===      * Retornar *      ===---                   //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Tela de Login e Cadastro * ==-- //
void login_cadastro(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Login/Cadastro * ==---                       //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---===      * Entrar *       ===---                    //\n");
    printf("//             (* 2 *) ---===     * Registrar *     ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Tela de Cadastro * ==-- //
void cadastro(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---== * Cadastrar-se * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome:                                                         //\n");
    printf("//         --== Usuário:                                                      //\n");
    printf("//         --== Email:                                                        //\n");
    printf("//         --== Função (Usuário/Cozinheiro):                                  //\n");
    printf("//         --== Senha:                                                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Tela de Autenticação * ==-- //
void autenticacao(void) {
    system("clear||cls");
    yellow();
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---== * Autenticação * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --= Usuário/Email:                                                 //\n");
    printf("//         --= Senha:                                                         //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Tela de Informações * ==-- //
void menu_informacoes(void) {
    system("clear||cls");
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
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
    reset_color();
}



// --== * Informações sobre a Equipe * ==-- //
void menu_equipe(void) {
    system("clear||cls");
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
    reset_color();
}