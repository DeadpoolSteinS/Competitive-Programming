#include <cstdio>
#include <algorithm>
#include <cmath>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    int n;
    scan(n);
    char arr[n+5];
    scanf(" %c", &arr[0]);
    printf("%c", arr[0]);
    for(int i = 1; i < n; i++){
        scanf(" %c", &arr[i]);
        if(arr[i] != arr[i-1])
            printf("%c", arr[i]);
    }
    printf("\n");
    return 0;
}