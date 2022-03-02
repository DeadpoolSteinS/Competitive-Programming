#include <cstdio>
#include <cmath>
#define gc getchar_unlocked
using namespace std;

void scan(long long &angka){
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
    long long b, k;
    scan(b); scan(k);
    k -= b;
    b = pow(2, 61);
    while(k > 0){
        if(k >= b){
            k -= b;
            printf("%lld\n", b);
        }
        b /= 2;
    }
    return 0;
}