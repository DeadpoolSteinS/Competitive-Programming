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
    int n, m, q;
    scan(n); scan(m); scan(q);
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int help = i & j;
            if(help == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    int a, b, c, d;
    while(q--){
        scan(a); scan(b); scan(c); scan(d);
        for(int i = a; i <= c; i++){
            for(int j = b; j <= d; j++){
                if(a[i][j+1])
            }
        }
    }
    return 0;
}