#include <cstdio>
#include <cstring>
#include <cctype>
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
    int t;
    scan(t);
    for(int i = 1; i <= t; i++){
        int n, a, b, k;
        scan(n); scan(a); scan(b); scan(k);
        printf("Kasus #%d: ", i);
        printf("%d\n", n+(b-a)*k);
    }
    return 0;
}