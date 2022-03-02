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
    string great;
    getline(cin, great);
    string benar = "halo dunia";
    int total = 0;
    for(int i = 0; i < great.length(); i++){
        if(tolower(great[i]) == tolower(benar[i]))
            total++;
    }
    cout << total << endl;
    return 0;
}