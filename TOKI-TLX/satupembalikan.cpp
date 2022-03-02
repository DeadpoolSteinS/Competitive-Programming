#include <cstdio>
#define gc getchar
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
    int n, total = 0;
    scan(n);
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        scan(a[i]);
    for(int i = 0; i < n; i++){
        scan(b[i]);
        if(a[i] == b[i])
            total++;
    }
    printf("%d\n", total);
    return 0;
}