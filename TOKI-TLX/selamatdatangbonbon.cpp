#include <cstdio>
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
    long long x, y, z;
    scan(x); scan(y); scan(z);
    printf("%lld\n", x*(100-y)*(100+z)/10000);
    return 0;
}