#include <iostream>
#include <list>
using namespace std;

struct Item{
	int codigo;
	string nome;
	int preco;
	int status;
};

int hash_aux(int k,int m){
	return k % m;	
}

int hash_linear(int k,int m, int i){
	return (hash_aux(k,m)+i)%m;	
}

int inserir_item(Item tabela_hash[], Item valor, int m){
	int pos = -1, i = 0;
	while(i<m){
		pos = hash_aux(valor.codigo, m);
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos] = valor;
			tabela_hash[pos].status = 1;
			return pos;
		}
		i++;
	}
	return -1;	
}

int buscar_item(Item tabela_hash[], int codigo, int m){
	int pos, i = 0, status = 1;
	while(i<m){
		pos = hash_linear(codigo, m, i);
		status = tabela_hash[pos].status;

		if(tabela_hash[pos].codigo == codigo){
			return pos;
		}
		i++;
	}
	return -1;		
}

int main(){
	setlocale(LC_ALL,"");
	
	const int m = 53;
	
	Item tabela_hash[m];
	list<int> vendas, compras;
	
	Item item;	
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>item.codigo;
		cin>>item.nome;
		cin>>item.preco;
		inserir_item(tabela_hash, item, m);
	}
	
	int vi;
	cin>>vi;
	while(vi != -1){
		vendas.push_back(vi);
		cin>>vi;
	}
	
	int ci;
	cin>>ci;
	while(ci != -1){
		compras.push_back(ci);
		cin>>ci;
	}
	
	int v, c, cod_item, pos_item, l=0;
	cin>>v>>c;
	while(v){
		cod_item = vendas.front();
		vendas.pop_front();
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		l += item.preco;
		v--;
	}
	while(c){
		cod_item = compras.front();
		compras.pop_front();
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		l -= item.preco;
		c--;
	}
	
	cout<<l<<" moeda(s)."<<endl;
	
	return 0;
}