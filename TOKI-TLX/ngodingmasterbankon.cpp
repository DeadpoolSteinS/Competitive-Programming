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
    int a, b, c, k;
    scan(a); scan(b); scan(c); scan(k);
    if(a > b)
        swap(a, b);
    if(a > c)
        swap(a, c);
    if(b > c)
        swap(b, c);
    if(k == 0)
        printf("%d %d %d\n", c, b, a);
    else
        printf("%d %d %d\n", a, b, c);
    return 0;
}