# Simulado APEX em C++

Material de estudo para a prova de APEX — **Vetores, Matrizes e Funcoes Recursivas**.

Pagina unica, sem dependencias: abra o `index.html` ou acesse pelo GitHub Pages.

## O que tem

1. **A base** — os 4 tipos de funcao (do `func1.cpp` da aula), passagem por valor x referencia,
   ponteiros, vetor como ponteiro, matriz com `MAX` e a estrutura caso base + chamada recursiva.
   Inclui uma tabela C x C++, porque a lista do professor esta escrita em C.
2. **Blocos prontos para a `main`** — sortear vetor de inteiros e de reais numa faixa,
   ler a ordem e montar a matriz, exibir com `setw`.
3. **Simulado: 14 questoes, 56 lacunas** — o codigo vem com lacunas numeradas, o botao
   *Conferir* marca certo/errado e o gabarito traz as respostas e a explicacao escrita.
   - Bloco A: os 4 tipos de funcao, fatorial iterativo x recursivo, potencia sem `pow`.
   - Bloco B e C: as questoes 1 a 4 da lista (vetores e matrizes).
   - Bloco D e E: ponteiros, aritmetica de ponteiros, inverter vetor, busca binaria.
4. **So explique** — 5 trechos para simular na mao e descrever o que fazem.
5. **Erros que custam ponto** e **checklist final** de 15 itens.

As respostas digitadas e os itens do checklist ficam salvos no navegador (localStorage).

## solucoes.cpp

Todas as funcoes do gabarito num arquivo so, com uma `main` que imprime o resultado
esperado ao lado do obtido. Compile e rode para conferir:

```
g++ -Wall -o solucoes solucoes.cpp
./solucoes
```

## Publicar no GitHub Pages

Em **Settings > Pages**, selecione Source: *Deploy from a branch*, branch `main` e pasta `/ (root)`.
