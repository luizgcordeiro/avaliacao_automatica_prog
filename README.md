# Criação de questões auto-avaliativas de programação

Este é um projeto para criação de questões auto-avaliativas em disciplinas de programação e similares, com foco de uso para VPLs e VPL Questions em Moodle.

### Direitos autorais / Copyright Notice

Copyright (c) 2025 Luiz Gustavo Cordeiro

Este projeto é distribuído sob a licença **GNU General Public License v3.0 (GPL-3.0)**. Você tem permissão para usar, estudar, modificar e redistribuir este software, desde que  mantenha este aviso de copyright e distribua quaisquer versões derivadas sob a mesma licença.

Para mais detalhes, consulte o arquivo `LICENSE` ou acesse:  
https://www.gnu.org/licenses/gpl-3.0.en.html

# Descrição do problema

A criação de questões auto-avaliativas é feita em várias etapas:

1. Criação do enunciado-problema;
2. Determinação do tipo de resposta;
3. Geração de testes;
4. Criação e aplicação do avaliador.

Cada etapa conta com diversas particularidades, e a resposta de um dos itens tem consequências na resposta dos outros.

Este projeto é focado em apresentar soluções para as etapas acima, de modo que se tenha, ao final, um avaliador automático para questões de programação com entrada e saída padrão (<code>stdin</code>, <code>stdout</code>) em C. Diversas alternativas são apresentadas, que podem ser aplicadas em diferentes contextos.

## 1. Criação do enunciado-problema

Esta é uma etapa criativa, e depende da experiência do profissional que cria as questões.

## 2. Determinação do tipo de resposta

Existem várias possibilidades para o tipo de resposta esperado em uma questão de programação em C. Focaremos em duas:

- Criação de um programa (com <code>main()</code>, incluindo bibliotecas, etc.) que recebe dados da entrada padrão e mostra dados na saída padrão.
- Criação de funções com comportamento específico.

Essas variações são encontradas em sites de treino de programação. Por exemplo, as questões do [HackerRank](https://www.hackerrank.com) e do [beecrowd](https://beecrowd.com/) lidam com entrada e saída padrão; As questões do [LeetCode](https://leetcode.com/) pedem funções de comportamento específico.

## 3. Geração de testes

A geração de testes depende do tipo de questão e do tipo de resposta esperada. Novamente, focaremos em duas

- Criação de testes estáticos (após gerados, sempre os mesmos testes são aplicados)
- Criação dinâmica de testes (uma lista de testes é criada em cada iteração do avaliador)

Embora a criação de testes estáticos possa ser manual, focaremos na geração automática dos testes estáticos.

A criação dinâmica de testes será feita em conjunto com o avaliador.

## 4. Criação e aplicação do avaliador

Por fim, também temos ao menos duas possibilidades para os avaliadores:

- Utilizar um avaliador já consolidado (e.g. [BIOTES do Moodle VPL](https://vpl.dis.ulpgc.es/documentation/vpl-3.4.3+/biotes.html));
- Criar e implementar um avaliador específico.

Note que a utilização de avaliadores já consolidados interfere na solução do item 3, pois estes requerem que os testes tenham algum tipo de formato pré-determinado.

# Soluções apresentadas

São apresentadas 4 soluções (em ordem crescente de complexidade) para diferentes escolhas das etapas:

#### S1

- Questões que pedem um programa que recebe e mostra dados na saída padrão
- Testes estáticos
- Utilização de BIOTES

#### S2

- Questões que pedem funções de comportamento espécífico
- Testes estáticos
- Utilização de BIOTES

#### S3

- Questões que pedem funções de comportamento específico
- Testes dinâmicos
- Utilização de avaliador específico.

#### S4

- Questões que pedem um programa que recebe e mostra dados na saída padrão
- Testes dinâmicos
- Utilização de avaliador específico

