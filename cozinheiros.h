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
    char receita[52];
    char descricao[257];
    char ingredientes[30][30];
    char materiais[30][30];
    char tempo[7];
    char modo[256];
    char complex[3];
    char status;
};

void modulo_cozinheiro(void);
char menu_cozinheiro(void);
void cadastra_receita(void);
void altera_receita(void);
void deleta_receita(void);


