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
    int n, m;
    scan(n); scan(m);
    printf("Think of a number, any number\n");
    printf("Multiply it by %d\n", n);
    printf("Add %d to your number\n", n*m);
    printf("Now, divide your total by %d\n", n);
    printf("Finally, subtract the result from the first number you pick\n");
    printf("BRAVO!!!\n");
    printf("Your answer is %d\n", m);
    return 0;
}