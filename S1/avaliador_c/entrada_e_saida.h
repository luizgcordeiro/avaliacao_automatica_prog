/* COMEÇO ESPECÍFICO PARA QUESTÃO */

typedef struct {
    int m;
    int n;
    int **M;
} ENTRADA;

typedef struct {
    int m;
    int n;
    int **M;
} SAIDA;

typedef struct {
    int max_order;
    int min_order;
} LIMITES_ENTRADA;

typedef void SOLUCAO(int m, int n, int M[m][n]);

/* FIM ESPECÍFICO PARA QUESTÃO */

SAIDA * avaliar(SOLUCAO * funcao, ENTRADA * entrada);

ENTRADA * gerar_entrada(LIMITES_ENTRADA limites);

int saidas_iguais(SAIDA * s1, SAIDA * s2);

void mostrar_saida(SAIDA * saida);

void liberar_entrada(ENTRADA * entrada);

void liberar_saida(SAIDA * saida);