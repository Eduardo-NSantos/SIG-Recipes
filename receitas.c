#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include "usuario.h"
#include "uteis.h"

typedef struct receita Rec;

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
                altera_receita(id_usuario);
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
int altera_receita(int id_cozinheiro) {
    int id_receita = ver_receitas();

    Rec* receita_atual = buscaReceita(id_receita);
    if(receita_atual->id_cozinheiro != id_cozinheiro){
        printf("//    Essa receita não e sua, você só pode alterar suas próprias receitas!\n");
        printf("\n");
        printf("                    -------======= *  * =======-------                    \n");
        printf("                  ---== Aperte ENTER para continuar ==---                 \n");
        getchar();

        return 0;
    }

    if(id_receita == 0){
        return -1;
    }
    printf("//    Tem certeza que deseja alterar essa receita?\n");
    printf("//    1 - Sim\n");
    printf("//    2 - Não\n");
    char* escolha = input();
    if(strcmp(escolha, "1")){
        printf("//    Você escolheu um digito diferente de 1, portanto sua resposta será considerada como 'não'\n");
        printf("\n");
        printf("                       -------======= *  * =======-------                       \n");
        printf("                     ---== Aperte ENTER para continuar ==---                    \n");
        getchar();

        return 0;
    }

    char* nova_receita;
    char* nova_descricao;
    char* novo_ingredientes;
    char* novo_materiais;
    char* novo_tempo;
    char* novo_modo;
    char* novo_complex;

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
    printf("//         --== Novo nome da Receita: ");
    nova_receita = input();
    while (!valida_receita(nova_receita)) {
        printf("//         --== Dado inválido, digite novamente: ");
        nova_receita = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Nova complexidade (1-5): ");
    novo_complex = input();
    while (!valida_complexidade(novo_complex)) {
        printf("//         --== Dado inválido, digite novamente: ");
        novo_complex = input();
    }

    printf("//                                                                            //\n");
    printf("//         --== Novo tempo de Preparo (Formato 00:00): ");
    novo_tempo = input();
    while (!valida_tempo(novo_tempo)) {
        printf("//         --== Dado inválido, digite novamente: ");
        novo_tempo = input();
    }

    printf("//                                                                            //\n"); 
    printf("//         --== Novos ingredientes: ");
    novo_ingredientes = input();
    while (!valida_ingredientes(novo_ingredientes)) {
        printf("//         --== Valor inválido, digite novamente: ");
        novo_ingredientes = input();
    }

    printf("//         --== Novos materiais: ");
    novo_materiais = input();
    while (!valida_materiais(novo_materiais)) {
        printf("//         --== Valor inválido, digite novamente: ");
        novo_materiais = input();
    }

    printf("//                                                                            //\n");
    printf("//                      ---== * Nova descricao * ==---                        //\n");
    printf("\n");
    printf("--== ");                                                 
    nova_descricao = input();
    while (!valida_descricao(nova_descricao)) {
        printf("--== Inválido, digite novamente: ");
        nova_descricao = input();
    }

    printf("//                                                                            //\n"); 
    printf("//                    ---== * Novo modo de Preparo * ==---                    //\n");
    printf("\n");
    printf("--== ");
    novo_modo = input();
    while (!valida_modo(novo_modo)) {
        printf("--== Inválido, digite novamente: ");
        novo_modo = input();
    }
    preencheReceita(0, nova_receita, nova_descricao, novo_ingredientes, novo_materiais, novo_tempo, novo_modo, novo_complex, dados);
    if(atualiza_receita("receitas.dat", id_receita, dados)){
        printf("//                   ---== Receita editada com sucesso ==---                  //\n");
    }else{
        printf("//                     ---== Erro ao realizar edição ==---                    //\n");
    }
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();


    free(nova_receita);
    free(novo_complex);
    free(novo_ingredientes);
    free(novo_materiais);
    free(novo_tempo);
    free(nova_descricao);
    free(novo_modo);
    free(dados);

    return 1;
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

int receitas_por_ingrediente(char *arquivo){
    int conta_receitas = 0;

    FILE *fp = fopen(arquivo, "rb+");
    if (fp == NULL){
        printf("//  Não foi possivel realizar a busca");
        getchar();
        return 0;
    }
    
    system("clear||cls");
    printf("Ingrediente desejado: ");
    char* ingrediente = input();
    Rec receita;
    while (fread(&receita, sizeof(Rec), 1, fp)){
        if (strstr(receita.ingredientes, ingrediente) && receita.status) {
            printf("===============================================================================================\n");
            printf("//  Nome da receita: %s\n", receita.receita);
            printf("//  Tempo de preparo: %s\n", receita.tempo);
            printf("//  Ingredientes: %s\n", receita.ingredientes);
            printf("//  Materiais: %s\n", receita.materiais);
            printf("//  Modo de preparo: %s\n", receita.modo);

            conta_receitas++;
        }
    }

    if(conta_receitas == 0){
        printf("===============================================================================================");
        printf("// Ingrediente não encontrado");
    }
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    fclose(fp);
    return 0;
}
