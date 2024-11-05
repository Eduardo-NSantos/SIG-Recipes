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
    char receita[52];
    char descricao[257];
    char ingredientes[257];
    char materiais[257];
    char tempo[7] = "00:00";
    char modo[257];
    char complexidade[3] = "1";

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
    do{
        if(!valida_receita(receita)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Nome: ");
        scanf("%51[^\n]s", receita);
        getchar();
    }while(!valida_receita(receita));

    do{
        if(!valida_descricao(descricao)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Descrição: ");
        scanf("%256[^\n]s", descricao);
        getchar();
    }while(!valida_descricao(descricao));

    printf("//         --== Ingredientes: ");
    scanf("%256[^\n]s", ingredientes);
    getchar();
    printf("//         --== Materiais: ");
    scanf("%256[^\n]s", materiais);
    getchar();

    do{
        if(!valida_tempo(tempo)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Tempo de Preparo (hh:mm): ");
        scanf("%6[^\n]s", tempo);
        getchar();
    }while(!valida_tempo(tempo));

    do{
        if(!valida_modo(modo)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Modo de Preparo: ");
        scanf("%256[^\n]s", modo);
        getchar();
    }while(!valida_modo(modo));

    do{
        if(!valida_complexidade(complexidade)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Complexidade (1-5): ");
        scanf("%2[^\n]s", complexidade);
        getchar();
    }while(!valida_complexidade(complexidade));

    printf("\n%s", receita);
    printf("\n%s", descricao);
    printf("\n%s", ingredientes);
    printf("\n%s", materiais);
    printf("\n%s", tempo);
    printf("\n%s", modo);
    printf("\n%s\n", complexidade);
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}



// --== * Altera Receitas  * ==-- //
void altera_receita(void) {
    char receita[52];
    char descricao[257];
    char ingredientes[257];
    char materiais[257];
    char tempo[7] = "00:00";
    char modo[257];
    char complexidade[3] = "1";

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * alterar Receita * ==---                      //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    do{
        if(!valida_receita(receita)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Nome: ");
        scanf("%51[^\n]s", receita);
        getchar();
    }while(!valida_receita(receita));

    do{
        if(!valida_descricao(descricao)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Descrição: ");
        scanf("%256[^\n]s", descricao);
        getchar();
    }while(!valida_descricao(descricao));

    printf("//         --== Ingredientes: ");
    scanf("%256[^\n]s", ingredientes);
    getchar();
    printf("//         --== Materiais: ");
    scanf("%256[^\n]s", materiais);
    getchar();

    do{
        if(!valida_tempo(tempo)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Tempo de Preparo (hh:mm): ");
        scanf("%6[^\n]s", tempo);
        getchar();
    }while(!valida_tempo(tempo));

    do{
        if(!valida_modo(modo)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Modo de Preparo: ");
        scanf("%256[^\n]s", modo);
        getchar();
    }while(!valida_modo(modo));

    do{
        if(!valida_complexidade(complexidade)){
            printf("Erro ao cadastrar item, verifique os dados e tente novamente!\n");
        }
        printf("//         --== Complexidade (1-5): ");
        scanf("%2[^\n]s", complexidade);
        getchar();
    }while(!valida_complexidade(complexidade));

    printf("\n%s", receita);
    printf("\n%s", descricao);
    printf("\n%s", ingredientes);
    printf("\n%s", materiais);
    printf("\n%s", tempo);
    printf("\n%s", modo);
    printf("\n%s\n", complexidade);
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
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




