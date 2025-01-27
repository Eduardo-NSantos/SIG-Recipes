#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "uteis.h"


void modulo_usuario(int id) {
    char opcao;

    do {
        opcao = menu_usuario();
        switch (opcao) {
            case '1':
                ver_dados(id);
                break;
            case '2':
                altera_dados(id);
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
    char status[8];

    if(usuario->status == '1'){
        strcpy(status, "ativo");
    } else {
        strcpy(status, "inativo");
    }

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
    printf("//    ---===  Status: %s\n", status);
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
void altera_dados(int id) {
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
    printf("//         --== Novo nome: ");
    nome = input();
    while (!valida_nome(nome)) {
        printf("//         --== Dado inválido, digite novamente: ");
        nome = input();
    }
    printf("//         --== Novo email: ");
    email = input();
    while (!valida_email(email)) {
        printf("//         --== Dado inválido, digite novamente: ");
        email = input();
    }
    printf("//         --== Nova senha: ");
    senha = input();
    while (!valida_senha(senha)) {
        printf("//         --== Dado inválido, digite novamente: ");
        senha = input();
    }
    printf("//                                                                            //\n");
    strcpy(usuario->nome, nome);
    strcpy(usuario->email, email);
    strcpy(usuario->senha, senha);
    if(atualizaUsuario("usuarios.dat", id, usuario)){
        printf("//                   ---== Usuário editado com sucesso ==---                  //\n");
    }else{
        printf("//                     ---== Erro ao realizar edição ==---                    //\n");
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
        long posicao = (id - 1) * sizeof(Usuario);
        fseek(file, posicao, SEEK_SET);
        fwrite(usuario, sizeof(Usuario), 1, file);
        printf("\n");
        printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
        printf("//                                                                            //\n");
        printf("//                 ---=== Usuário excluído com sucesso ===---                 //\n");
        exit(0);
    }else{
        printf("\n");
        printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
        printf("//                                                                            //\n");
        printf("//                      ---=== Exclusão cancelada ===---                      //\n");
    }

    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");
    getchar();

    fclose(file);
}

void lista_usuarios(char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario usuario;
    system("clear||cls");
    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        printf("========================================================================\n");
        printf("//  %d - ", usuario.id); 
        printf("Nome: %s\n", usuario.nome);
        printf("//    - Email: %s\n", usuario.email);
        printf("//    - Status: %s\n", usuario.status == '1' ? "Ativo" : "Inativo");
    }

    printf("\n ==| Tecle enter para continuar");
    getchar();

    fclose(file);
}

int compararNomes(const void* a, const void* b) {
    Usuario* usuarioA = (Usuario*)a;
    Usuario* usuarioB = (Usuario*)b;
    return strcmp(usuarioA->nome, usuarioB->nome);
}

void buscarEListarUsuariosOrdenados(const char* arquivo) {
    FILE* file;
    Usuario* usuarios;
    Usuario usuarioTemp;
    int quantidade = 0;
    int capacidade = 10;

    usuarios = (Usuario*)malloc(capacidade * sizeof(Usuario));
    if (usuarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    file = fopen(arquivo, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(usuarios);
        return;
    }

    while (fread(&usuarioTemp, sizeof(Usuario), 1, file)) {
        if (quantidade >= capacidade) {
            capacidade *= 2;
            usuarios = (Usuario*)realloc(usuarios, capacidade * sizeof(Usuario));
            if (usuarios == NULL) {
                printf("Erro ao realocar memória.\n");
                fclose(file);
                return;
            }
        }
        usuarios[quantidade++] = usuarioTemp;
    }

    fclose(file);

    qsort(usuarios, quantidade, sizeof(Usuario), compararNomes);

    printf("\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("//                                                                            //\n");
    printf("//               ---== * Listar por ordem alfabética * ==---                  //\n");
    printf("//                                                                            //\n");
    printf("//((((((((((((((((((((((((((((((((((((****))))))))))))))))))))))))))))))))))))//\n");
    printf("\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d, Nome: %s, Status: %c\n", usuarios[i].id, usuarios[i].nome, usuarios[i].status);
    }
    printf("\n");
    printf("                       -------======= *  * =======-------                       \n");
    printf("                     ---== Aperte ENTER para continuar ==---                    \n");

    free(usuarios);
}