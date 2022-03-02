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

const int MAKS = 1e5+7;

int main(){
    int n, a, awal = -1;
    scan(n);
    int arr[MAKS] = {};
    for(int i = 0; i < n; i++){
        scan(a);
        if(i == 0)
            awal = a;
        if(arr[a] == 0 && awal != a)
            arr[a] = i;
    }
    scan(n);
    while(n--){
        scan(a);
        if(arr[a] == 0 && a != awal)
            printf("-1\n");
        else
            printf("%d\n", arr[a]);
    }
    return 0;
}