#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "receitas.h"
#include "usuario.h"

void modulo_relatorio(int id_usuario) {
    char opcao;

    do {
        opcao = menu_relatorio();
        switch (opcao) {
            case '1':
                ver_dados(id_usuario);
                break;
            case '2':
                ver_receitas();
                break;
            case '3':
                receitas_por_ingrediente("receitas.dat");
                break;
        }
    } while (opcao != '0');
}

// --== * Menu Relatório * ==-- //
char menu_relatorio(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                      ---== * Menu Relatório * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//     (* 1 *)              ---===  * Ver perfil *  ===---                    //\n");
    printf("//     (* 2 *)           ---===  * Consultar Receitas *  ===---               //\n");
    printf("//     (* 3 *)  ---===  * Consultar Receitas por ingrediente *  ===---        //\n");
    printf("//     (* 0 *)           ---===      * Retornar *      ===---                 //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}





