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
    long long n, m;
    scan(n);
    m = sqrt(n);
    if(m*m == n)
        printf("%lld\n", m);
    else
        printf("0\n");
    return 0;
}