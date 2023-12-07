#include <iostream>
using namespace std;

//função para realizar de busca binária
int buscaBinaria(int vetor[], int tamanho, int x)
{
	int esq = 0; // Índice da esquerda (primeiro elemento indice 0)
	int dir = tamanho - 1; // Índice da direita (ultimo elemento, como o vetor começa no 0 é necessário esse -1)
	int meio;
	bool achou = false;
	
	while (esq <= dir && achou == false) // enquanto a esquerda for maior ou igual a direita ainda a indices para analise (PENSAR EM MEIO)
	{
		meio = (esq + dir) / 2; // meio do vetor
	
		if (x == vetor[meio]) { //ordem aqui
      		achou = true;
    	} else if (x < vetor[meio]) {
      	  	  dir = meio - 1;
    	} else {
      	  esq = meio + 1;
    	}
	}
	
		if(achou)
		{
				return meio;
		}else{
				return -1;
		}
	}
		int main()
		{
			int n;
			int ids[20]; 
			int tamanho = 0;
			int busca;


			cin >> n;
			while (n != -1) // toda vez que o número digitado for diferente de 0 e nn ter mais de 20 ids armazenadas no vetor
			{
				ids[tamanho] = n; // armazena um valor pra id em cada posição
				tamanho++;
				cin >> n;
			}

			int idDesejada;
			cin >> idDesejada;

			busca = buscaBinaria(ids, tamanho, idDesejada);
			
			if(busca == -1)
			{
				cout << "Nao possui acesso" << endl;
			}else{
				cout << "Possui acesso" << endl;
	  	  	  }	

			return 0;
		}