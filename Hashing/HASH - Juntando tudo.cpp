#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct dado{
    int status;
    int k;
};

int h1(int k, int m)
{
    int res;
    
    //k mod m
    res = k % m; 
        if(res < 0)
            res += m;
            
 return res;
}


int h2(int k, int m)
{
    return 1 + (k%(m-1));
}

int dhash(int k, int i, int m)
{
    int res;
    res = h1(k,m)+i*h2(k,m)%m;
        if(res < 0)
            res += m;
        if(res >= m)
            res -= m;
            
return res;
}


int hash_insert(dado t[], int m, int k)
{
    int i = 0;
    int j = 0;
    
do{
        j = dhash(k,i,m);
    if (t[j].status != 1)
    {
        t[j].k = k;
        t[j].status = 1;
        return j;
    }else i++;
}while (i != m);

return -1;
}

// procura o elemento desejado
int hash_search(dado t[], int m, int k){
    int i; 
    int j; 
    i = 0;
    
    do{
    j = dhash(k,i,m);
        if (t[j].k == k)
            return j;
        else i++;
    }while (t[j].status != 0 && i < m);
    
    return -1;
}

// funcao para remocao de chave 
int hash_remove(dado t[], int m, int k)
{
    int j;
    j = hash_search(t,m,k);
    
    if(j != -1)
    {
    t[j].status = 2;
    t[j].k = -1;
    return 0; // consegui remover
    }else return -1; // k nao esta na tabela
}

int main()
{
    int i, j;
    int k, k2;
    int m;
    int r;
    dado t[50];
    int op;

    cin >> m;

    for(i = 0; i < m; i++){
        t[i].k = -1;
        t[i].status = 0;
    }
    
    do{
        cin >> op;

        switch (op){
        
            case 1:
                cin >> k;
                hash_insert(t, m, k);
            break;
        
            case 2:
                cin >> k2;

                if(hash_search(t, m, k2) == -1)
                    cout << hash_search(t, m, k2);

                else
                    cout << hash_search(t, m, k2);

                cout << endl;
            break;

            case 3:
                cin >> r;
                hash_remove(t, m, r);
            break;

            case 4:
                for(j = 0; j < m; j++)
                    cout << t[j].k << " ";

                cout << endl;
            break;

            case 5:
            break;
        }
        
    } while(op != 5);
    
    return 0;
    
}