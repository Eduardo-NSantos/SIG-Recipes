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


// --== * Assinaturas * ==-- //
typedef struct receita Rec;
struct receita {
    int id;
    int id_cozinheiro;
    char receita[52];
    char descricao[257];
    char ingredientes[500];
    char materiais[257];
    char tempo[7];
    char modo[256];
    char complex[3];
    char status;
};

void modulo_cozinheiro(int);
char menu_cozinheiro(void);
void cadastra_receita(int);
void altera_receita(void);
void deleta_receita(void);
void expandir_receita(int);
int ver_receitas(void);


