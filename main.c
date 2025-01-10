//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                Universidade Federal do Rio Grande do Norte                 //
//                         Disciplina de Programação                          //
//                          Prof, Flavius Gorgônio                            //
//                      Moisés Lucena, Isaque Guimarães                       //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                Versão 0.8                                  //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//

#include <stdio.h>
#include <stdlib.h>
#include "informacoes.h"
#include "usuario.h"
#include "receitas.h"
#include "relatorio.h"



// --== * Assinaturas * ==-- //
char menu_inicio(void);
char menu_principal(void);
//       --== ** ==--        //





//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//



// --== * Função Principal * ==-- //
int main(void) {
    char opcao;
    char opcao_principal;
    int id;
    
    do {
        opcao = menu_inicio();
        switch (opcao) {
            case '1':
                id = autenticacao();
                if (id == 0) {
                    break;
                } else {
                    do {
                    opcao_principal = menu_principal();
                    switch (opcao_principal) {
                        case '1':
                            modulo_cozinheiro(id);
                            break;
                        case '2':
                            modulo_usuario(id);
                            break;
                        case '3':
                            modulo_relatorio(id);
                            break;
                        case '4':
                            modulo_informacoes();
                            break;
                        }    
                } while (opcao_principal != '0');
                break;
                }
            case '2':
                cadastro();
                break;
        }
    } while (opcao != '0');

    

    return 0;
}



// --== * Menu Inicial * ==-- //
char menu_inicio(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                         ---== * Menu Início * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---===      * Entrar *       ===---                    //\n");
    printf("//             (* 2 *) ---===     * Cadastrar *     ===---                    //\n");
    printf("//             (* 0 *) ---===       * Sair *        ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}



// --== * Menu Principal * ==-- //
char menu_principal(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Menu Principal * ==---                       //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//             (* 1 *) ---===  *  Menu Receitas  *  ===---                    //\n");
    printf("//             (* 2 *) ---===  *  Menu Usuário   *  ===---                    //\n");
    printf("//             (* 3 *) ---===  *  Menu Relatório *  ===---                    //\n");
    printf("//             (* 4 *) ---===  *  Informações    *  ===---                    //\n");
    printf("//             (* 0 *) ---===       * Sair *        ===---                    //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}
