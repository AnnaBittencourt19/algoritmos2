#include <iostream>
#include <cmath>

using namespace std;

//funcao linear
int hash_aux(int k, int m)
{
	int h;

	//k mod m
	h = k % m;

	if (h < 0)
	{
		h += m;
	}

	return h;
}

int hash2(int k, int i, int m, int c1, int c2)// tem que declarar c1,c2
{
	// h(k,i)=(h'(k)+c1i+c2i2)modm

	int H;
	int res;

	//sondagem linear
	res = hash_aux(k, m);
	H = (res + c1*i + c2 * pow(i,2));

	return H%m;
}


int main()
{
	int m; //tamanho da tabela
	int k; //chave a ser inserida na tabela
	int i = 0;
	int c1, c2;
	
	cin >> k >> m >> c1 >> c2;

	
  // imprimindo o resultado da função hash2 para cada valor de i
	for(i = 0; i < m; i++)
	{
		cout << hash2(k, i, m, c1, c2) << " "; // só imprimir  e boa
	}

	return 0;

}