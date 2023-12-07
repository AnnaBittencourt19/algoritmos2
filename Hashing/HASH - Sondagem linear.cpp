 #include <iostream>
  using namespace std; 
  int hash_aux(int k, int m) {
   // h(k,m) = k mod m (padrão método da divisão mod = %)
    int h;
     h = k % m; 
     if (h < 0) {// se h retornar um número negativo 
      h += m; // some m
      }
      return h;
   } 
   
   int hash1(int k, int i,int m){//funcao lineae
        return(hash_aux(k,m)+i)%m; //h(k,i,m) = h(k)+i mod m
   }
        

 int main() { 
     int k, m; 
     cin >> k; 
     cin >> m; 
     int h;
     
     // imprimindo os elementos
    for(int i=0; i<m; i++){
        cout << hash1(k,i,m) << " ";
        
          }
          return 0;
          }