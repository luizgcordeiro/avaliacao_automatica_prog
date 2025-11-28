#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "entrada_e_saida.h"
#include "auxs.h"
#include "solucao.h"
#include "gabarito.h"
#include "avaliador.h"

// NÃO DEVE SER MODIFICADO
int main() {
    srand(time(0));
    int acertos = 0;
    int testes = 0;
    
    while (testes<MAX_TESTS) {
        
        testes++;
        
        ENTRADA * entrada = gerar_entrada(limites_entrada);
        
        SAIDA * saida_esperada = avaliar(gabarito, entrada);
        SAIDA * saida_obtida = avaliar(solucao, entrada);
        
        int resposta_correta = saidas_iguais(saida_esperada, saida_obtida);
        
        if (resposta_correta) {
            // Acerto
            acertos++;
            printf("<|--\n-[Teste %d %s]\n\n--|>\n", testes, CHECK);
            
        } else {
            printf("Comment :=>>-[Teste %d] %s\n", testes, CROSS);
            printf("Comment :=>> -----------------\n");
            printf("Comment :=>> Entrada:\n");
            printf("<|--\n");
            mostrar_entrada(entrada);
            printf("--|>\n");
            printf("Comment :=>> -----------------\n");
            printf("Comment :=>> Resultado obtido:\n");
            printf("<|--\n");
            mostrar_saida(saida_obtida);
            printf("--|>\n");
            printf("Comment :=>> -----------------\n");
            printf("Comment :=>> Resultado esperado:\n");
            printf("<|--\nM = \n");
            mostrar_saida(saida_esperada);
            printf("--|>\n");
            printf("Comment :=>> -----------------\n");
        }

        liberar_entrada(entrada);
        liberar_saida(saida_esperada);
        liberar_saida(saida_obtida);
    }
    
    printf("Comment :=>> -----------------\n");
    printf("Comment :=>> | RESULTADO     |\n");
    printf("Comment :=>> | Testes: %5d |\n", testes);
    printf("Comment :=>> | Acertos: %4d |\n", acertos);
    printf("Comment :=>> -----------------\n");
    printf("Grade :=>> %.2lf", 10*(double)acertos/testes);
}

