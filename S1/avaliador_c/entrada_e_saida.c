#include <stdio.h>
#include <stdlib.h>
#include <auxs.h>
#include "entrada_e_saida.h"

// TUDO AQUI É ESPECÍFICO PARA A QUESTÃO

SAIDA * avaliar(SOLUCAO * funcao, ENTRADA * entrada) {
    int m = entrada->m;
    int n = entrada->n;
    int M[m][n];
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            M[i][j] = (entrada->M)[i][j];
        }
    }

    funcao(m,n,M);

    SAIDA * saida = (SAIDA *)malloc(sizeof(SAIDA));
    saida->m = m;
    saida->n = n;
    saida->M = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        saida->M[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            saida->M[i][j] = M[i][j];
        }
    }
    return saida;
}

ENTRADA * gerar_entrada(LIMITES_ENTRADA limites) {
    int max_order = limites.max_order;
    int min_order = limites.min_order;
    ENTRADA * entrada = (ENTRADA *)malloc(sizeof(ENTRADA));
    int m = randint(min_order, max_order + 1);
    int n = randint(min_order, max_order + 1);
    entrada->m = m;
    entrada->n = n;
    entrada->M = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        entrada->M[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            entrada->M[i][j] = rand()%100;
        }
    }
    return entrada;
}

int saidas_iguais(SAIDA * s1, SAIDA * s2) {
    if (s1->m != s2->m || s1->n != s2->n) {
        return 0;
    }
    for (int i = 0; i < s1->m; i++) {
        for (int j = 0; j < s1->n; j++) {
            if (s1->M[i][j] != s2->M[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void mostrar_entrada(ENTRADA * entrada) {
    int m = entrada->m;
    int n = entrada->n;
    int **M = entrada->M;
    int M_as_matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            M_as_matrix[i][j] = M[i][j];
        }
    }
    printf("M = \n");
    show_matrix(m,n,M);
}

void mostrar_saida(SAIDA * saida) {
    int m = saida->m;
    int n = saida->n;
    int **M = saida->M;
    int M_as_matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            M_as_matrix[i][j] = M[i][j];
        }
    }
    printf("M = \n");
    show_matrix(m,n,M);
}

void liberar_entrada(ENTRADA * entrada) {
    for (int i = 0; i < entrada->m; i++) {
        free(entrada->M[i]);
    }
    free(entrada->M);
    free(entrada);
}

void liberar_saida(SAIDA * saida) {
    free(saida->M);
    free(saida);
}

