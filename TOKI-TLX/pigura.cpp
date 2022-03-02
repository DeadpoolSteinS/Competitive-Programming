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
    int a, c;
    char b;
    scan(a); scanf(" %c", &b); scan(c);
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= a; j++){
            if(i == 1 || i == a || j == 1 || j == a)
                printf("%d", c);
            else if(a%2 == 1 && i == (a+1)/2 && j == (a+1)/2)
                printf("*");
            else
                printf("%c", b);
        }
        printf("\n");
    }
    return 0;
}