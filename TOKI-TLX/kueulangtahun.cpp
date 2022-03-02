#include <cstdio>
#include <algorithm>
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
    long long n;
    scan(n);
    while(n--){
        long long a, b, kecil = 1e6+7, total = 0;
        scan(a);
        for(long long i = 0; i < a; i++){
            scan(b);
            kecil = min(kecil, b);
            total += b;
        }
        printf("%lld\n", (long long)total-(kecil*a));
    }
    return 0;
}