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
    long long n, a, total = 0;
    scan(n);
    for(int i = 0; i < n*2; i++){
        scan(a);
        total += a;
    }
    printf("%lld\n", total*n);
    return 0;
}