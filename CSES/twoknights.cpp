#include <cstdio>
#define gc getchar_unlocked
#define ull unsigned long long
using namespace std;

void scan(ull &angka){
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

int main(){
    ull n;
    scan(n);
    for(int i = 1; i <= n; i++){
        ull a = i*i;            // total way of knight1
        ull b = a-1;            // total way of knight2
        ull c = a*b/2;          // total all
        ull d = 4*(i-1)*(i-2);  // total way attaked
        printf("%lld\n", c-d);
    }
    return 0;
}