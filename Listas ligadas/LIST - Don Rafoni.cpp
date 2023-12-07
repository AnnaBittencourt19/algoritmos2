#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// definição de uma estrutura chamada dados_div
struct dados_div {
    char nome_div[50];  // definição da estrutura que armazena o nome
    int div;            // definição da estrutura que armazena o valor numérico
};

int main() {
    int i;
    int N;
    char nome[50];

    dados_div pessoa;                     // declaração da variável de tipo dados_div
    list <dados_div> registro;            // criação da lista para armazenar registros
    list <dados_div> :: iterator p;       // declaração do iterador para percorrer a lista

    cin >> N;                             // leitura da quantidade de registros

    // loop para ler N registros de dados
    for (i = 0; i < N; i++){
        cin.ignore();
        cin.getline(pessoa.nome_div, 50);  // leitura do nome usando getline para considerar espaços em branco
        cin >> pessoa.div;                 // leitura da dívida

        registro.push_back(pessoa);        // adiciona o registro na lista
    }

    cin.ignore();
    cin.getline(nome, 50);                 // leitura de um nome para buscar e remover registros correspondentes

    // loop para percorrer a lista de registros
    for (p = registro.begin(); p != registro.end(); ++p){
        if (!strcmp(nome, p->nome_div)) {  // compara o nome fornecido com o nome do registro atual
            p = registro.erase(p);         // remove o registro da lista
        }
    }

    // loop para exibir os registros restantes
    for (p = registro.begin(); p != registro.end(); ++p) {
        cout << p->nome_div << endl;      // exibe o nome do registro
        cout << p->div << endl;           // exibe a dívida do registro
    }

    while (!registro.empty()) {
        registro.pop_front();             // limpa a lista
    }

    return 0;
}
