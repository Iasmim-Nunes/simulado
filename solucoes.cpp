#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX = 20;

int somaVetor(int v[], int n, int i){
	if(i==n) return 0;
	return v[i]+somaVetor(v,n,i+1);
}
int indiceDoMaior(float v[], int n, int i){
	if(i==n-1) return i;
	int idxResto = indiceDoMaior(v,n,i+1);
	if(v[i]>=v[idxResto]) return i;
	return idxResto;
}
int somaPrincipal(int m[][MAX], int n, int i){
	if(i==n) return 0;
	return m[i][i]+somaPrincipal(m,n,i+1);
}
int somaSecundaria(int m[][MAX], int n, int i){
	if(i==n) return 0;
	return m[i][n-1-i]+somaSecundaria(m,n,i+1);
}
int buscaRecursiva(int m[][MAX], int n, int alvo, int pos){
	if(pos==n*n) return 0;
	int linha = pos/n;
	int coluna = pos%n;
	bool achou = (m[linha][coluna]==alvo);
	if(achou) cout<<"  encontrado em ("<<linha<<","<<coluna<<")"<<endl;
	return achou+buscaRecursiva(m,n,alvo,pos+1);
}
int somaLinha(int m[][MAX], int n, int i, int j){
	if(j==n) return 0;
	return m[i][j]+somaLinha(m,n,i,j+1);
}
int somaMatriz(int m[][MAX], int n, int i){
	if(i==n) return 0;
	return somaLinha(m,n,i,0)+somaMatriz(m,n,i+1);
}
int eleva(int base, int expo){
	if(expo==0) return 1;
	return base*eleva(base,expo-1);
}
int fatorial(int n){
	if(n==0) return 1;
	return n*fatorial(n-1);
}
int somaPtr(int *p, int n){
	if(n==0) return 0;
	return *p+somaPtr(p+1,n-1);
}
void inverte(int v[], int ini, int fim){
	if(ini>=fim) return;
	int aux=v[ini]; v[ini]=v[fim]; v[fim]=aux;
	inverte(v,ini+1,fim-1);
}
void minMax(int v[], int n, int i, int *menor, int *maior){
	if(i==n) return;
	if(v[i]<*menor) *menor=v[i];
	if(v[i]>*maior) *maior=v[i];
	minMax(v,n,i+1,menor,maior);
}
int buscaBinaria(int v[], int ini, int fim, int chave){
	if(ini>fim) return -1;
	int meio=(ini+fim)/2;
	if(v[meio]==chave) return meio;
	if(chave<v[meio]) return buscaBinaria(v,ini,meio-1,chave);
	return buscaBinaria(v,meio+1,fim,chave);
}
void troca(int *a, int *b){ int aux=*a; *a=*b; *b=aux; }
int f(int n){ if(n==0) return 0; return n%10+f(n/10); }
void g(int n){ if(n==0) return; g(n/2); cout<<n%2; }
int h(int v[], int n, int i, int x){ if(i==n) return 0; return (v[i]==x)+h(v,n,i+1,x); }
void t(int m[][MAX], int n, int i, int j){
	if(i==n) return;
	if(j==n){ t(m,n,i+1,0); return; }
	if(i<j){ int aux=m[i][j]; m[i][j]=m[j][i]; m[j][i]=aux; }
	t(m,n,i,j+1);
}
void pv(int x){ x=x*2; }
void pp(int *x){ *x=*x*2; }
void pr(int &x){ x=x*2; }

int main(){
	int v[5]={2,4,6,8,10};
	cout<<"Q4 soma {2,4,6,8,10} = "<<somaVetor(v,5,0)<<"  (esperado 30)"<<endl;

	float r[5]={8,12,5,12,3};
	cout<<"Q5 maior de {8,12,5,12,3} -> pos "<<indiceDoMaior(r,5,0)<<"  (esperado 1)"<<endl;

	int m[MAX][MAX];
	int k=1;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) m[i][j]=k++;
	cout<<"Q6 diagonal principal (1,6,11,16) = "<<somaPrincipal(m,4,0)<<"  (esperado 34)"<<endl;
	cout<<"Q7 diagonal secundaria (4,7,10,13) = "<<somaSecundaria(m,4,0)<<"  (esperado 34)"<<endl;
	cout<<"Q13 soma da matriz 1..16 = "<<somaMatriz(m,4,0)<<"  (esperado 136)"<<endl;

	int b[MAX][MAX]={{7,0,7},{0,0,0},{0,7,0}};
	cout<<"Q8 busca do 7 em 3x3:"<<endl;
	cout<<"   total = "<<buscaRecursiva(b,3,7,0)<<"  (esperado 3)"<<endl;

	cout<<"Q3 eleva(5,3) = "<<eleva(5,3)<<"  (esperado 125)"<<endl;
	cout<<"Q2 fatorial(5) = "<<fatorial(5)<<"  fatorial(0) = "<<fatorial(0)<<"  (120 e 1)"<<endl;
	cout<<"Q11 somaPtr = "<<somaPtr(v,5)<<"  (esperado 30)"<<endl;

	inverte(v,0,4);
	cout<<"Q12 invertido: "; for(int i=0;i<5;i++) cout<<v[i]<<" "; cout<<" (10 8 6 4 2)"<<endl;

	int w[6]={4,-2,9,9,1,0},menor=w[0],maior=w[0];
	minMax(w,6,1,&menor,&maior);
	cout<<"Q10 menor="<<menor<<" maior="<<maior<<"  (esperado -2 e 9)"<<endl;

	int ord[7]={1,3,5,7,9,11,13};
	cout<<"Q14 busca binaria do 9 -> "<<buscaBinaria(ord,0,6,9)<<"  do 8 -> "<<buscaBinaria(ord,0,6,8)<<"  (4 e -1)"<<endl;

	int x=10,y=20; troca(&x,&y);
	cout<<"Q9 troca: "<<x<<" "<<y<<"  (esperado 20 10)"<<endl;

	cout<<"T1 f(472) = "<<f(472)<<"  (esperado 13)"<<endl;
	cout<<"T2 g(10) = "; g(10); cout<<"  (esperado 1010)"<<endl;
	int vv[6]={3,7,7,1,7,2};
	cout<<"T3 h conta 7 = "<<h(vv,6,0,7)<<"  (esperado 3)"<<endl;

	t(m,4,0,0);
	cout<<"T4 transposta linha 0: "; for(int j=0;j<4;j++) cout<<m[0][j]<<" "; cout<<" (1 5 9 13)"<<endl;

	int z=5;
	cout<<"T5 ";
	pv(z); cout<<z<<" ";
	pp(&z); cout<<z<<" ";
	pr(z); cout<<z<<"  (esperado 5 10 20)"<<endl;
}
