#include <cstdio>
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
    int n, m, total = 1;
    scan(n); scan(m);
    for(int i = 0; i < n*m-1; i++)
        total = (total << 1) % 998244353;
    printf("%d\n", total);
    return 0;
}