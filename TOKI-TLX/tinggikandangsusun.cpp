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
    long long n, k, a, total = 1, maksimal = 0, hitung = 0;
    scan(n); scan(k);
    while(n--){
        if(hitung == 0)
            total++;
        scan(a);
        hitung++;
        maksimal = max(maksimal, a);
        if(hitung == k){
            total += maksimal;
            hitung = 0;
            maksimal = 0;
        }
    }
    printf("%lld\n", total+maksimal);
    return 0;
}