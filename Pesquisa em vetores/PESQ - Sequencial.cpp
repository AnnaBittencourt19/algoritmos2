#include <iostream>

using namespace std;

int busca(int vetor[], int tamanho, int x)
{
	// função para buscar o número que está sendo procurado
	bool encontrado = false; // 0 = false
	int i = 0; //contador = verificação de vetores

	//while se for verdadeiro continua
	//repetição para ver se o valor de x foi encontrado
	while (encontrado == false && i < tamanho) //enquanto encontrado for falso e i < que tamanho (nn percorreu todo o vetor essa repetição ira acontecer)
		encontrado = vetor[i++] == x; // encontrado mudará seu valor para verdadeiro caso o valor que o usuario deseja esteja no vetor
	//vetor[i++] = cada vez que se "passa" no loop é analisada uma posição do vetor
	if (encontrado == true) //número encontrado
		return (i - 1); // esse -1 é pq o contador começa no 0 então para dizer a "colocação" exata do número precisa realizar essa subtração
	else return -1;   //se não encontrar retorna -1
}

int main()
{
	int res;
	int x;
	int n;
	int v[100];
	int i = 0;

	do //"repetição sem requisitos"
	{
		cin >> n;
		if (n != -1) // se o número digitado for diferente de -1
		{
			v[i] = n; //atribui o valor do número digitado em uma posição do vetor
			i++; //"andar" no vetor
		}
	}
	while (n != -1); //se 

	cin >> x;

	res = busca(v, i, x); //chamando a função e declata o valor do return pra ela

	if(res == -1) // else return -1, numero nn encontrado
	{
		cout << x << " nao encontrado" << endl;
	}
	else cout << x << " encontrado na posicao " << res << endl; // esse else é caso o return nn seja -1 então o numero foi encontrado

	return 0;
}
