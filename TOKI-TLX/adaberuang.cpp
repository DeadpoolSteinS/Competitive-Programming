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
    int n, d, index = 0, total = 0;
    scan(n); scan(d);
    int arr[n+5];
    for(int i = 1; i <= n; i++){
        scan(arr[i]);
        while(arr[index+1] <= arr[i]-d)
            index++;
        if(index > 0 && arr[index] == arr[i]-d)
            total++;
    }
    printf("%d\n", total);
    return 0;
}