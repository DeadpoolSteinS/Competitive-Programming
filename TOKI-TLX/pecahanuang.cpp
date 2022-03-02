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
    int n, arr[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    scan(n);
    for(int i = 0; i < 10; i++){
        if(arr[i] <= n){
            printf("%d %d\n", arr[i], (int)n/arr[i]);
            n %= arr[i];
        }
    }
    return 0;
}