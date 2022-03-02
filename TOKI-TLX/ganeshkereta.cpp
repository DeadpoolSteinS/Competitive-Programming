#include <cstdio>
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
    int arr[n];
    for(int i = 0; i < n; i++){
        scan(arr[i]);
    }
    for(int i = n-1; i >= 0; i--){
        printf("%d", arr[i]);
        if(i > 0)
            printf(",");
        else
            printf("\n");
    }
}