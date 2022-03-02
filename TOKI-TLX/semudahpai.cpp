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
    int n;
    scan(n);
    for(int i = 0; i < n; i++){
        if(i%3 == 0)
            printf("a");
        else if(i%3 == 1)
            printf("b");
        else
            printf("c");
    }
    printf("\n");
    return 0;
}