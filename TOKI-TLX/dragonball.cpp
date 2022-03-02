#include <cstdio>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

void loop(char a, int n){
    for(int i = 0; i < n; i++){
        printf("%c", a);
    }
}

int main(){
    int n, a;
    scan(n);
    while(n--){
        scan(a);
        printf("k"); loop('a', a);
        printf("m"); loop('e', a);
        printf("h"); loop('a', a);
        printf("m"); loop('e', a);
        printf("h"); loop('a', a);
        printf("\n");
    }
    return 0;
}