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
    int a, b, c, x = 2;
    scan(a); scan(b); scan(c);
    while(x%a == 0 || x%b == 0 || x%c == 0)
        x++;
    printf("%d\n", x);
    return 0;
}