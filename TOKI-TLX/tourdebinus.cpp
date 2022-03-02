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
    int n, a[2];
    char arah[2][10];
    scan(n);
    int arr[n+1], empty[n+1] = {}, total[n+1] = {};
    for(int i = 1; i <= n; i++){
        scan(arr[i]);
        empty[i] = empty[i-1] + (arr[i] == 0);
        total[i] = total[i-1] + arr[i];
    }
    scan(a[0]); scanf("%s", arah[0]);
    scan(a[1]); scanf("%s", arah[1]);
    printf("%d %d\n", (arah[0][0] == 'r') ? total[n]-total[a[0]-1] : total[a[0]], (arah[1][0] == 'r') ? empty[n]-empty[a[1]-1] : empty[a[1]]);
    return 0;
}