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
#include "usuario.h"
#include "uteis.h"



//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//
//                                                                            //
//                                  FUNÇÕES                                   //
//                                                                            //
//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//



void modulo_usuario(int id) {
    char opcao;

    do {
        opcao = menu_usuario();
        switch (opcao) {
            case '1':
                ver_dados(id);
                break;
            case '2':
                altera_dados();
                break;
            case '3':
                deleta_conta(id);
                break;
        }
    } while (opcao != '0');
}



// --== * Menu do Usuário * ==-- //
char menu_usuario(void) {
    char opcao;
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Menu Usuário * ==---                         //\n");
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
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha o destino desejado: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}

// --== * Visualiza Dados * ==-- //
void ver_dados(int id) {
    Usuario* usuario;
    usuario = buscaUsuario(id);

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                            ---== * Dados * ==---                           //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//    ---===  Nome: %s\n", usuario->nome);
    printf("//    ---===  Email: %s\n", usuario->email);
    printf("//    ---===  Status: %c\n", usuario->status);
    printf("//    ---===  Número de Receitas: (* *)                                       //\n");
    printf("//                                                                            //\n");
    printf("//    ---=== Informações Adicionais:                                          //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                ----==== Receitas mais Favoritadas ====----                 //\n");
    printf("//                                                                            //\n");
    printf("//                        (* ID *) Receita 1                                  //\n");
    printf("//                        (* ID *) Receita 2                                  //\n");
    printf("//                        (* ID *) Receita 3                                  //\n");
    printf("//                        (* 0 *)  Retornar                                   //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();
}




// --== * Tela de Cadastro * ==-- //
void cadastro(void) {
    char* nome;
    char* email;
    char* senha;
    Usuario* usuario;
    usuario = (Usuario*) malloc(sizeof(Usuario));

    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---== * Cadastrar-se * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome: ");
    nome = input();
    while (!valida_nome(nome)) {
        printf("//         --== Dado inválido, digite novamente: ");
        nome = input();
    }
    printf("//         --== Email: ");
    email = input();
    while (!valida_email(email)) {
        printf("//         --== Dado inválido, digite novamente: ");
        email = input();
    }
    printf("//         --== Senha: ");
    senha = input();
    while (!valida_senha(senha)) {
        printf("//         --== Dado inválido, digite novamente: ");
        senha = input();
    }
    printf("//                                                                            //\n");
    strcpy(usuario->nome, nome);
    strcpy(usuario->email, email);
    strcpy(usuario->senha, senha);
    usuario->status = '1';
    if(gravacao_usuario("usuarios.dat", usuario)){
        printf("//                 ---== Usuário cadastrado com sucesso ==---                 //\n");
        printf("ID: %d", usuario->id);
    }else{
        printf("//                   ---== Erro ao realizar cadastro ==---                    //\n");
    }
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    free(nome);
    free(email);
    free(senha);
    free(usuario);
}



// --== * Tela de Autenticação * ==-- //
int autenticacao(void) {    
    char* email;
    char* senha;
    int id_user;
    
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                        ---== * Autenticação * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Email: ");
    email = input();
    while (!valida_email(email)) {
        printf("//         --== Dado inválido, digite novamente: ");
        email = input();
    }

    printf("//         --== Senha: ");
    senha = input();
    while (!valida_senha(senha)) {
        printf("//         --== Dado inválido, digite novamente: ");
        senha = input();
    }
    printf("//                                                                            //\n");
    id_user = autentica_usuario(email, senha);
    if (id_user == 0) {
        printf("//           ---== Dados inválidos, retornando à tela inicial ==---           //\n");
    } else {
        printf("//                   ---== Login Efetuado com sucesso ==---                   //\n");
    }
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    free(email);
    free(senha);
    return id_user;
}




// --== * Altera Dados * ==-- //
void altera_dados(void) {
    char* nome;
    char* email;
    char* senha;
    Usuario* usuario;
    usuario = (Usuario*) malloc(sizeof(Usuario));  
    
    system("clear||cls");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//                       ---== * Alterar Dados * ==---                        //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//         --== Nome: ");
    nome = input();
    while (!valida_nome(nome)) {
        printf("//         --== Dado inválido, digite novamente: ");
        nome = input();
    }
    printf("//         --== Email: ");
    email = input();
    while (!valida_email(email)) {
        printf("//         --== Dado inválido, digite novamente: ");
        email = input();
    }
    printf("//         --== Senha: ");
    senha = input();
    while (!valida_senha(senha)) {
        printf("//         --== Dado inválido, digite novamente: ");
        senha = input();
    }
    printf("//                                                                            //\n");
    printf("//         ---== Informações Adicionais (Opcional):                           //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    strcpy(usuario->nome, nome);
    strcpy(usuario->email, email);
    strcpy(usuario->senha, senha);

    free(nome);
    free(email);
    free(senha);
    free(usuario);
}



// --== * Deletar Conta * ==-- //
void deleta_conta(int id) {
    FILE* file;
    file = fopen("usuarios.dat", "r+b");
    Usuario* usuario;
    usuario = buscaUsuario(id);
    char opcao;

    system("clear||cls");
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
    printf("                       -------======= *  * =======-------                       \n");
    printf("               --== Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    if (opcao == 's' || opcao == 'S') {
        usuario->status = '0';
        fwrite(usuario, sizeof(Usuario), 1, file);
    }

    fclose(file);
}