  #include <iostream>
  using namespace std; 
  int hash_aux(int k, int m) {
   // h(k,m) = k mod m (padrão método da divisão mod = %)
    int h;
     h = k % m; 
     if (h < 0) // se h retornar um número negativo {
      h += m; // some m
      return h;
   } 
        
       int main() { 
       int k, m; 
       cin >> k; 
       cin >> m; 
       int h;
        while (k != 0 && m != 0) // enquanto k e m diferentes de 0, exibir o valor de h 
        {
         h = hash_aux(k, m); 
         cout << h << endl; 
         cin >> k; 
          cin >> m; 
          } 
          } 