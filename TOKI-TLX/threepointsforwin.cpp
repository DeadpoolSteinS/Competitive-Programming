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
    int n, a, total = 0;
    scan(n);
    int binus[n];
    for(int i = 0; i < n; i++)
        scan(binus[i]);
    for(int i = 0; i < n; i++){
        scan(a);
        if(a == binus[i])
            total++;
        else if(a < binus[i])
            total += 3;
    }
    printf("%d\n", total);
    return 0;
}