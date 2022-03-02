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

int solve(int a, int b, int c){
    if(c <= 2000)
        return a;
    else{
        c -= 2000;
        c *= b;
        c /= 100;
    }
    return a+c;
}

int main(){
    int n, a, b, l;
    scan(n);
    while(n--){
        scan(a); scan(b); scan(l);
        printf("%d\n", solve(a, b, l));
    }
    return 0;
}