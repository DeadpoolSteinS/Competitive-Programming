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
    long long q, k, c, o;
    scan(q); scan(k);
    while(q--){
        scan(c);
        o = c | k;
        if(o == c)
            printf("%lld\n", c);
        else
            printf("-1\n");
    }
    return 0;
}