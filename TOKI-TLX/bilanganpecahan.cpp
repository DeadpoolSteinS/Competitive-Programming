#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
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

int main(){
    int n, m;
    scan(n); scan(m);
    if(__gcd(n, m) >= 2)
        printf("%d %d\n", n / __gcd(n, m), m / __gcd(n, m));
    else
        printf("Tidak\n");
    return 0;
}