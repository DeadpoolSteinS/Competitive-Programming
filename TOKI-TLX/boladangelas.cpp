#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    int n, m, a, b;
    scan(n); scan(m);
    int arr[n+1] = {};
    for(int i = 0; i < m; i++){
        scan(a); scan(b);
        if(arr[a] > 0 && arr[b] > 0)
            swap(arr[a], arr[b]);
        else if(arr[a] > 0){
            arr[b] = arr[a];
            arr[a] = b;
        }
        else if(arr[b] > 0){
            arr[a] = arr[b];
            arr[b] = a;
        }
        else{
            arr[a] = b;
            arr[b] = a;
        }
    }
    scan(b);
    while(b--){
        scan(a);
        printf("%d\n", (arr[a] == 0) ? a : arr[a]);
    }
    return 0;
}