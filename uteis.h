typedef struct receita Rec;

char* input(void);
int ehDigito(char*);
int valida_email(char*);
int valida_nome(char*);
int valida_senha(char*);
int valida_receita(char*);
int valida_descricao(char*);
int valida_tamanho(char*);
void preencheReceita(char*, char*, char*, char*, char*, Rec* dados);
void valida_ingredientes(char**, int, Rec* dados);
void valida_materiais(char**, int, Rec* dados);
int valida_tempo(char*);
int valida_complexidade(char*);
int valida_modo(char*);