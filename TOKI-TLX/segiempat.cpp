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
    int n, m, a, b;
    scan(n); scan(m);
    scan(a); scan(b);
    printf("%d\n", max((n/a)*(m/b), (n/b)*(m/a)));
    return 0;
}