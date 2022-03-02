#include <cstdio>
#define gc getchar_unlocked
// #define gc getchar
using namespace std;
 
void scan(int &angka){
    angka = 0; bool negative = false; char input = gc();
    while((input < '0') || (input > '9')){
        if(input == '-') negative = true;
        input = gc();
    }
    while(input >= '0' && input <= '9'){
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if(negative) angka = -angka;
}
 
const int MAX = 1e9+7;
 
int main(){
    int n, m = 1;
    scan(n);
    for(int i = 0; i < n; i++){
        m = (m << 1) % MAX;
    }
    printf("%d\n", m);
    return 0;
}