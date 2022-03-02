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
    int a, b;
    scan(a); scan(b);
    int bukit = max(a, b), lembah = min(a, b), biggest = abs(a-b);
    while(scanf("%d", &a) != EOF){
        if(a > b)
            bukit = a;
        else if(a < b)
            lembah = a;
        biggest = max(abs(bukit-lembah), biggest);
        b = a;
    }
    printf("%d\n", biggest);
    return 0;
}