#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> estoque; // lista para armazenar o estoque de produtos
    list<int> venda;    // lista para armazenar os produtos vendidos

    int N, operacao, codigo;

    cin >> N;

    // loop para processar as operações
    for (int i = 0; i < N; i++)
    {
        cin >> operacao;

        // se a operação for 1, adiciona um novo código ao estoque
        if (operacao == 1)
        {
            cin >> codigo;
            estoque.push_front(codigo);
        }
        // se a operação for diferente de 1, realiza uma venda
        else
        {
            codigo = estoque.back(); // obtém o último código do estoque
            estoque.pop_back();       // remove o último código do estoque
            venda.push_front(codigo); // adiciona o código vendido à lista de vendas
        }
    }

    // imprime o estoque
    cout << "estoque: ";
    for (list<int>::iterator it = estoque.begin(); it != estoque.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    // imprime as vendas
    cout << "venda: ";
    for (list<int>::iterator it = venda.begin(); it != venda.end(); it++)
    {
        cout << *it << " ";
    }

    // limpa o estoque e as vendas antes de encerrar o programa
    while (!estoque.empty())
        estoque.pop_front();

    while (!venda.empty())
        venda.pop_front();

    return 0;
}
