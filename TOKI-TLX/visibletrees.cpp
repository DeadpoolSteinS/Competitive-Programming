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
    int arr[n][n], col[n] = {}, row[n] = {}, bantu[n] = {};
    for(int i = 0; i < n; i++){
        int help = 0;
        for(int j = 0; j < n; j++){
            scan(arr[i][j]);
            if(help < arr[i][j]){
                help = arr[i][j];
                row[i]++;
            }
            if(bantu[j] < arr[i][j]){
                bantu[j] = arr[i][j];
                col[j]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d", col[i]);
        if(i < n-1)
            printf(" ");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", row[i]);
    }
    return 0;
}