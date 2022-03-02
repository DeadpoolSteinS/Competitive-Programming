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
    int a, b, c;
    scan(a); scan(b); scan(c);
    int total = a + b + c, maxim = max(max(a, b), c);
    if((total/7)*4 == maxim)
        printf("YA\n");
    else
        printf("TIDAK\n");
    return 0;
}