#include <iostream>
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
    long long q, k = 0, c, o;
    scan(q);
    while(q--){
        scan(c);
        k++;
        if(k != c){
            k = 0;
            cout << "SALAH\n";
        }
        else
            cout << "BENAR\n";
        cout << flush;
    }
    return 0;
}