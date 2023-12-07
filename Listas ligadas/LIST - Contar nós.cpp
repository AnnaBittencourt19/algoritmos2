#include <iostream>
#include <list>

using namespace std;

// função para contar os elementos em uma lista
int contar(list<int> lista)
{
    int cont = 0;

    // itera sobre a lista
    for (list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        cont++; // incrementa o contador para cada elemento na lista
    }

    return cont; // retorna o total de elementos na lista
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

    // chama a função para contar e imprimir o número de elementos na lista
    cout << "numero de elementos na lista: " << contar(fila) << endl;

    // limpa a lista antes de encerrar o programa
    while (!fila.empty())
        fila.pop_front();

    return 0;
}
