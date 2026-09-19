// Gabarito do Simulado APEX em C++ - todas as funcoes num arquivo so.
// Mesmo estilo dos exercicios entregues: matriz achatada com int *mat,
// parametros de saida por referencia e recursao no lugar dos lacos.
//
//   g++ -Wall -o solucoes solucoes.cpp
//   ./solucoes

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Bloco A: funcoes e parametros (arquivos da aula) ----------

int mult(int a, int b){
	int m;
	m = a * b;
	return m;
}

int fatorial(int n){
	if(n==0)//caso base ou trivial
		return 1;
	return n*fatorial(n-1);//chamada recursiva
}

int eleva(int base, int expo){
	if(expo==0)//caso base ou trivial
		return 1;
	return base*eleva(base,expo-1);//chamada recursiva
}

// ---------- Bloco B: vetores (Exercicios 1 e 2) ----------

void preencherVetor(int vetor[], int tamanho, int indice) {
    if (indice == tamanho) {
        return;
    }
    vetor[indice] = rand() % 10;
    preencherVetor(vetor, tamanho, indice + 1);
}

int somaRecursiva(int vetor[], int tamanho, int indice) {
    if (indice == tamanho) {
        return 0;
    }
    return vetor[indice] + somaRecursiva(vetor, tamanho, indice + 1);
}

void exibirVetor(int vetor[], int tamanho, int indice) {
    if (indice == tamanho) {
        cout << endl;
        return;
    }
    cout << vetor[indice] << " ";
    exibirVetor(vetor, tamanho, indice + 1);
}

// o > (e nao >=) e o que mantem a PRIMEIRA ocorrencia do maior
void encontrarMaior(double vetor[], int tamanho, int indice,
                    double &maiorValor, int &posicaoMaior) {
    if (indice == tamanho) {
        return;
    }
    if (vetor[indice] > maiorValor) {
        maiorValor = vetor[indice];
        posicaoMaior = indice;
    }
    encontrarMaior(vetor, tamanho, indice + 1, maiorValor, posicaoMaior);
}

// ---------- Bloco C: matrizes achatadas (Exercicios 3 e 4) ----------

int somaDiagonalPrincipal(int *mat, int ordem, int indice){
	if(indice==ordem)
		return 0;
	return mat[indice*ordem+indice] + somaDiagonalPrincipal(mat,ordem,indice+1);
}

int somaDiagonalSecundaria(int *mat, int ordem, int indice){
	if(indice==ordem)
		return 0;
	return mat[indice*ordem+(ordem-1-indice)] + somaDiagonalSecundaria(mat,ordem,indice+1);
}

void buscarValor(int *mat, int ordem, int k, int valor, int &contador){
	if(k==ordem*ordem)
		return;

	int linha  = k/ordem;
	int coluna = k%ordem;

	if(mat[k]==valor)
	{
		cout<<"   Ocorrencia "<<(contador+1)<<": linha "<<linha<<", coluna "<<coluna<<endl;
		contador++;
	}

	buscarValor(mat,ordem,k+1,valor,contador);
}

int somaLinha(int *mat, int ordem, int linha, int coluna){
	if(coluna==ordem)
		return 0;
	return mat[linha*ordem+coluna] + somaLinha(mat,ordem,linha,coluna+1);
}

int somaMatriz(int *mat, int ordem, int linha){
	if(linha==ordem)
		return 0;
	return somaLinha(mat,ordem,linha,0) + somaMatriz(mat,ordem,linha+1);
}

// transposta - trace T4
void transpor(int *mat, int ordem, int linha, int coluna){
	if(linha==ordem) return;
	if(coluna==ordem){ transpor(mat,ordem,linha+1,0); return; }

	if(linha<coluna){
		int aux = mat[linha*ordem+coluna];
		mat[linha*ordem+coluna] = mat[coluna*ordem+linha];
		mat[coluna*ordem+linha] = aux;
	}
	transpor(mat,ordem,linha,coluna+1);
}

// ---------- Bloco D: ponteiros ----------

void troca(int *a, int *b){
	int aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void minMax(int v[], int tamanho, int indice, int *menor, int *maior){
	if(indice==tamanho)
		return;
	if(v[indice] < *menor)
		*menor = v[indice];
	if(v[indice] > *maior)
		*maior = v[indice];
	minMax(v,tamanho,indice+1,menor,maior);
}

// ---------- Bloco E: extras ----------

int somaPtr(int *p, int tamanho){
	if(tamanho==0)
		return 0;
	return *p+somaPtr(p+1,tamanho-1);
}

void inverte(int vetor[], int inicio, int fim){
	if(inicio>=fim)
		return;
	int aux = vetor[inicio];
	vetor[inicio] = vetor[fim];
	vetor[fim] = aux;
	inverte(vetor,inicio+1,fim-1);
}

int buscaBinaria(int vetor[], int inicio, int fim, int chave){
	if(inicio>fim)
		return -1;
	int meio = (inicio+fim)/2;
	if(vetor[meio]==chave)
		return meio;
	if(chave<vetor[meio])
		return buscaBinaria(vetor,inicio,meio-1,chave);
	return buscaBinaria(vetor,meio+1,fim,chave);
}

// ---------- traces ----------

int somaDigitos(int n){ if(n==0) return 0; return n%10+somaDigitos(n/10); }
void binario(int n){ if(n==0) return; binario(n/2); cout<<n%2; }
int conta(int v[], int n, int i, int x){ if(i==n) return 0; return (v[i]==x)+conta(v,n,i+1,x); }
void porValor(int x){ x = x*2; }
void porPonteiro(int *x){ *x = *x*2; }
void porReferencia(int &x){ x = x*2; }

// ---------- conferencia ----------

int main(){
	srand(time(NULL));

	cout<<"== Bloco A =="<<endl;
	cout<<"Q1  mult(3,5)      = "<<mult(3,5)<<"\t(esperado 15)"<<endl;
	cout<<"Q2  fatorial(5)    = "<<fatorial(5)<<"\t(esperado 120)"<<endl;
	cout<<"Q2  fatorial(0)    = "<<fatorial(0)<<"\t(esperado 1)"<<endl;
	cout<<"Q3  eleva(5,3)     = "<<eleva(5,3)<<"\t(esperado 125)"<<endl;

	cout<<endl<<"== Bloco B =="<<endl;
	int numeros[5] = {2,4,6,8,10};
	cout<<"Q4  soma {2,4,6,8,10} = "<<somaRecursiva(numeros,5,0)<<"\t(esperado 30)"<<endl;
	cout<<"Q4  exibirVetor: ";
	exibirVetor(numeros,5,0);

	int sorteado[10];
	preencherVetor(sorteado,10,0);
	cout<<"Q4  preencherVetor (0 a 9): ";
	exibirVetor(sorteado,10,0);

	double reais[5] = {8,12,5,12,3};
	double maiorValor = reais[0];
	int posicaoMaior = 0;
	encontrarMaior(reais,5,1,maiorValor,posicaoMaior);
	cout<<fixed<<setprecision(1);
	cout<<"Q5  maior de {8,12,5,12,3} = "<<maiorValor<<" no indice "<<posicaoMaior
	    <<"\t(esperado 12.0 no indice 1 - a PRIMEIRA ocorrencia)"<<endl;

	cout<<endl<<"== Bloco C =="<<endl;
	int ordem = 4;
	int mat[4][4];
	int k = 1;
	for(int i=0;i<ordem;i++)
		for(int j=0;j<ordem;j++)
			mat[i][j] = k++;              // 1..16

	cout<<"    matriz de teste (1 a 16):"<<endl;
	for(int i=0;i<ordem;i++){
		cout<<"   ";
		for(int j=0;j<ordem;j++)
			cout<<setw(3)<<mat[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"Q6  diagonal principal  = "<<somaDiagonalPrincipal(&mat[0][0],ordem,0)
	    <<"\t(1+6+11+16 = 34)"<<endl;
	cout<<"Q6  diagonal secundaria = "<<somaDiagonalSecundaria(&mat[0][0],ordem,0)
	    <<"\t(4+7+10+13 = 34)"<<endl;
	cout<<"Q12 soma da matriz      = "<<somaMatriz(&mat[0][0],ordem,0)
	    <<"\t(1+2+...+16 = 136)"<<endl;

	int busca[3][3] = {{7,0,7},{0,0,0},{0,7,0}};
	int contador = 0;
	cout<<"Q7  busca do 7 numa 3x3:"<<endl;
	buscarValor(&busca[0][0],3,0,7,contador);
	cout<<"    total = "<<contador<<"\t(esperado 3, em (0,0) (0,2) (2,1))"<<endl;

	transpor(&mat[0][0],ordem,0,0);
	cout<<"T4  transposta, linha 0: ";
	for(int j=0;j<ordem;j++) cout<<mat[0][j]<<" ";
	cout<<"\t(esperado 1 5 9 13)"<<endl;

	cout<<endl<<"== Blocos D e E =="<<endl;
	int x=10,y=20;
	troca(&x,&y);
	cout<<"Q8  troca(10,20)   = "<<x<<" "<<y<<"\t(esperado 20 10)"<<endl;

	int w[6] = {4,-2,9,9,1,0};
	int menor = w[0], maior = w[0];
	minMax(w,6,1,&menor,&maior);
	cout<<"Q9  menor e maior  = "<<menor<<" e "<<maior<<"\t(esperado -2 e 9)"<<endl;

	cout<<"Q10 somaPtr        = "<<somaPtr(numeros,5)<<"\t(esperado 30)"<<endl;

	inverte(numeros,0,4);
	cout<<"Q11 invertido      = ";
	for(int i=0;i<5;i++) cout<<numeros[i]<<" ";
	cout<<"\t(esperado 10 8 6 4 2)"<<endl;

	int ordenado[7] = {1,3,5,7,9,11,13};
	cout<<"Q13 busca do 9     = "<<buscaBinaria(ordenado,0,6,9)
	    <<"\tbusca do 8 = "<<buscaBinaria(ordenado,0,6,8)<<"\t(esperado 4 e -1)"<<endl;

	cout<<endl<<"== Traces =="<<endl;
	cout<<"T1  soma digitos de 472 = "<<somaDigitos(472)<<"\t(esperado 13)"<<endl;
	cout<<"T2  binario de 10       = ";
	binario(10);
	cout<<"\t(esperado 1010)"<<endl;
	int rep[6] = {3,7,7,1,7,2};
	cout<<"T3  conta o 7           = "<<conta(rep,6,0,7)<<"\t(esperado 3)"<<endl;

	int v = 5;
	cout<<"T5  ";
	porValor(v);       cout<<v<<" ";
	porPonteiro(&v);   cout<<v<<" ";
	porReferencia(v);  cout<<v<<"\t(esperado 5 10 20)"<<endl;

	return 0;
}
