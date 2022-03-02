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
    int n, m;
    scan(n); scan(m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i%2 == 0 && j%2 == 0)
                printf("#");
            else if(i%2 == 1 && j%2 == 1)
                printf("*");
            else
                printf("$");
        }
        printf("\n");
    }
    return 0;
}