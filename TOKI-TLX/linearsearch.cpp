#include <cstdio>
#include <vector>
#include <cstring>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    int n, m, a;
    scan(n); scan(m);
    for(int i = 0; i < n; i++){
        scan(a);
        if(a == m){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}