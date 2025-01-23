// --== * Assinaturas * ==-- //
typedef struct usuario Usuario;
struct usuario{
    int id;
    char nome[55];
    char email[55];
    char senha[26];
    char status;
};

void modulo_usuario(int);
char menu_usuario(void);
void ver_dados(int);
void altera_dados(int);
void deleta_conta(int);
int autenticacao(void);
void cadastro(void);
void lista_usuarios(char*);