#include <iostream>
using namespace std;

// função de busca (nn será usada busca binaria)
int buscaSequencial(int vetor[], int tamanho, int x) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            return i; // posição em que o estudante está 
        }
    }
    return -1; // retorna -1 se o estudante não for encontrado
}

int main() {
    int n; 
    int matriculas[10000];
    int matriculaProcurada;
    int corredor;
    
    cin >> n;

    //repeticao para a entrada
    for (int i = 0; i < n; i++) {
        cin >> matriculas[i];
    }

    cin >> matriculaProcurada;

    // função de busca sequencial
    corredor = buscaSequencial(matriculas, n, matriculaProcurada);

    // usa o return da funcao
    if (corredor != -1) {
        cout << "Corredor " << corredor << endl;
    } else {
        cout << "Nao localizado" << endl; 
    }

    return 0;
}
