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
    int n;
    scan(n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scan(arr[i]);
    sort(arr, arr+n);
    if(n > 1)
        swap(arr[1], arr[n-1]);
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i < n-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}