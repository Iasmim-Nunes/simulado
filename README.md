# Simulado APEX em C++

Material de estudo para a prova de APEX — **Vetores, Matrizes e Funcoes Recursivas**.

Pagina unica, sem dependencias: abra o `index.html` ou acesse pelo GitHub Pages.

O codigo segue as solucoes que eu mesma entreguei: matriz achatada com `int *mat`,
parametros de saida por referencia (`int &contador`) e recursao no lugar de todo laco.

## O que tem

1. **A base** — os 4 tipos de funcao (do `func1.cpp` da aula), as tres passagens de
   parametro (valor, ponteiro, referencia), vetor como ponteiro e a estrutura
   caso base + chamada recursiva, incluindo o caso base de funcao `void`.
2. **A matriz achatada** — secao inteira sobre `&mat[0][0]`, `linha*ordem+coluna` e
   o caminho inverso `k/ordem` e `k%ordem`, que e a explicacao mais provavel de cair.
3. **Simulado: 13 questoes, 63 lacunas** — o codigo vem com lacunas numeradas, o botao
   *Conferir* marca certo/errado e o gabarito traz as respostas e a explicacao escrita.
   - Bloco A: os 4 tipos de funcao, fatorial iterativo x recursivo, potencia sem `pow`.
   - Bloco B: Exercicios 1 e 2 (vetores).
   - Bloco C: Exercicios 3 e 4 (matrizes).
   - Bloco D e E: ponteiros, aritmetica de ponteiros, inverter vetor, busca binaria.
4. **So explique** — 6 trechos para simular na mao e descrever o que fazem.
5. **Erros que custam ponto** e **checklist final** de 17 itens.

As respostas digitadas e os itens do checklist ficam salvos no navegador (localStorage).

## solucoes.cpp

Todas as funcoes do gabarito num arquivo so, com uma `main` que imprime o resultado
obtido ao lado do esperado. Compile e rode para conferir:

```
g++ -Wall -o solucoes solucoes.cpp
./solucoes
```

## Publicar no GitHub Pages

Em **Settings > Pages**, selecione Source: *Deploy from a branch*, branch `main` e pasta `/ (root)`.
