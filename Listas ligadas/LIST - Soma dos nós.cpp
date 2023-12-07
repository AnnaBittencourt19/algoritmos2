#include <iostream>
#include <list>

using namespace std;

// função para calcular a soma dos elementos em uma lista
int soma(list<int> lista)
{
    int soma = 0;

    // itera sobre a lista
    for (list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        soma += *it; // adiciona o valor atual ao total da soma
    }

    return soma; // retorna a soma total dos elementos na lista
}

int main()
{
    list<int> fila; // lista de números inteiros

    int flag = 1;
    while (flag)
    {
        int n;
        cin >> n;

        // se o valor lido for 0, encerra o loop
        if (n == 0)
        {
            flag = 0;
        }
        else
        {
            fila.push_back(n); // adiciona o valor lido à lista
        }
    }

    // chama a função para calcular e imprimir a soma dos elementos na lista
    cout << "soma dos números na lista: " << soma(fila) << endl;

    // limpa a lista antes de encerrar o programa
    while (!fila.empty())
        fila.pop_front();

    return 0;
}
