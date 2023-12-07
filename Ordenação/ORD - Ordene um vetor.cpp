#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab,esq,dir,pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir)/2.0)];
	
	do
	{
		while(vetor[esq] < pivo)
			esq++;
		while(vetor[dir] > pivo)
			dir--;
		if(esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}while(esq <= dir);
	
	if(dir-i >= 0)
		quickSort(vetor,tamanho,i,dir);
	if(j-esq >= 0)
		quickSort(vetor,tamanho,esq,j);
}

int main()
{
	int vetor[10];//define o vetor e sua quantidade máx.
	int tamanho;//define o tamanho que o usuario quer pro vetor
	int i=0, j; //contador
	int x=0; //contador
	int N; //valores do vetor
	
	cin>>N; //entra com os valores do vertor
	
	while(N!=-1)
	{
		vetor[x]=N; //armazena o valor no vetor
		x++;
		cin>>N;
	}
	tamanho=x; //define o tamanho do vetor
	
	j = tamanho-1; //define o tamanho de j (posição final do vetor)
	
	quickSort(vetor, tamanho, i, j);//chama a função
	
	for(x=0; x<tamanho; x++)//usa o for para mostrar os valores depois de ordenados
	{
		cout<<vetor[x]<<" ";
	}
	
	return 0;
}