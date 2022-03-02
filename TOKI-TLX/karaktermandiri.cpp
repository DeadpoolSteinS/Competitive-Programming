#include <iostream>
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
    int n;
    scan(n);
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    int i = 1;
    // bool masih = false;
    while(i < n){
        int jarak = 1;
        while(a[i] == a[i-1]){
            if(i + jarak >= n){
                // masih = true;
                break;
            }
            swap(a[i], a[i+jarak]);
            jarak++;
        }
        i++;
    }
    i = n-2;
    // bool masih = false;
    while(i >= 0){
        int jarak = 1;
        while(a[i] == a[i+1]){
            if(i - jarak < 0){
                // masih = true;
                break;
            }
            swap(a[i], a[i-jarak]);
            jarak++;
        }
        i--;
    }
    cout << a << endl;
    return 0;
}