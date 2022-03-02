#include <iostream>
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
    string kalimat;
    getline(cin, kalimat);
    string cari = "ideafuse";
    int n = kalimat.find(cari);
    if(n >= 0)
        n++;
    cout << n << endl;
    return 0;
}