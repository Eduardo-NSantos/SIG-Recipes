#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "receitas.h"
#include "usuario.h"

void modulo_relatorio(int id_usuario) {
    char opcao;
    int id_receita;

    do {
        opcao = menu_relatorio();
        switch (opcao) {
            case '1':
                ver_dados(id_usuario);
                break;
            case '2':
                id_receita = ver_receitas();
                if(id_receita == 0){
                    break;
                }
                expandir_receita(id_receita);
                break;
            case '3':
                receitas_por_ingrediente("receitas.dat");
                break;
            case '4':
                receitas_por_materiais("receitas.dat");
                break;
            case '5':
                lista_usuarios("usuarios.dat");
                break;
            case '6':
                printf("\n");
                buscarEListarUsuariosOrdenados("usuarios.dat");
                getchar();
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
    printf("//     (* 4 *)   ---===  * Consultar Receitas por materiais *  ===---         //\n");
    printf("//     (* 5 *)           ---===  * Listar usuários *   ===---                 //\n");
    printf("//     (* 6 *)   ---===  * Listar usuários por ordem alfabética *  ===---     //\n");
    printf("//     (* 0 *)           ---===      * Retornar *      ===---                 //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}





