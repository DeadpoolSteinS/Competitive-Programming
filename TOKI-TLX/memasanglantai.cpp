#include <cstdio>
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
    long long n;
    scan(n);
    if(n < 3)
        printf("1\n");
    long long arr[n+1] = {};
    arr[0] = 1; arr[1] = 1; arr[2] = 1;
    for(int i = 3; i <= n; i++)
        arr[i] = (arr[i-1] + arr[i-3]) % 1000000;
    printf("%lld\n", arr[n]);
    return 0;
}