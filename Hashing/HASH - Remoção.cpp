#include <iostream>
using namespace std;

//estrutura para armazenamento de dados na tabela hash
struct dado {
    int k;      // chave
    int status; // 0 = vazio, 1 = ocupado, -1 = excluído
};

//função para o cálculo da posição em que a chave k vai ser inserida em uma tabela de tamanho m
int hash_aux(int k, int m) {
    int h = k % m; //posição e fórmula hash (k mod m)
    if (h < 0) { // se h for negativo
        h += m; //some m no valor de h
    }
    return h;
}

//função que implementa a sondagem linear (caso haja colisões)
int hash1(int k, int i, int m) {
    return (hash_aux(k, m) + i) % m; //fórmula linear
}

//função que insere a chave k em uma tabela de tamanho m
int hash_insert(dado T[], int m, int k) {
    int i = 0; // tentativas
    do {
        int j = hash1(k, i, m); // posição
        if (T[j].status != 1) { //se estiver vazio
            T[j].k = k;
            T[j].status = 1; //muda status para ocupado
            return j; //retorna a posição
        } else { // se j estiver ocupado
            i = i + 1; // faz uma nova tentativa (sondagem linear)
        }
    } while (i != m);
    return -1;
}

// função que faz pesquisa na tabela
int hash_search(dado T[], int m, int k) {
    int i = 0;
    int j;

    do {
        j = hash1(k, i, m); // posição
        if (T[j].k == k && T[j].status == 1) { // verifica se k na posição j é igual a k buscada e está ocupada
            return j; // se sim, retorna a posição
        }
        i++;
    } while (T[j].status != 0 && i < m); // quando a posição estiver vazia ou i for maior que o número de elementos
    
    return -1; // retorna -1 se a chave não for encontrada
}

//função para remover
void hash_remove(dado T[], int m, int k) {
    int j = hash_search(T, m, k); // chama a função de busca
    if (j != -1) { // se a chave foi encontrada
        T[j].status = -1; // muda o status para -1, indicando que a chave foi removida
    }
}

//função principal
int main() {
    int m; //tamanho da tabela
    cin >> m;
    int p; //removida


    dado T[m]; //struct
    
    //inicializar a tabela
    for (int i = 0; i < m; i++) {
        T[i].k = -1; // enquanto não tiver nenhum valor, a posição tem o valor de -1
        T[i].status = 0; // vazio
    }

    int k;
    cin >> k;

    while (k != 0) { // enquanto k for diferente de 0
        int result = hash_insert(T, m, k); // calcula posição
        cin >> k; // e pede o valor de k
    }

    cin >> p;
    hash_remove(T, m, p); // chama a função de remoção
    
    
   

    // Mostrar a tabela após as remoções
    for (int i = 0; i < m; i++) { // for para "checar" as posições
        if (T[i].status == 1) { // quando estiver ocupado por uma chave
            cout << T[i].k; //imprime ela
        } else {// se não estiver ocupada (removida ou vazia)
            cout << "-1"; //imprime -1
        }
        cout << " ";
    }

    return 0;
}
