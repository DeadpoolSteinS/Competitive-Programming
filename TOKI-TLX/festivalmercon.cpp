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
    int n, a, benar = 0;
    scan(n);
    while(n--){
        scan(a);
        if(a%2 == 1)
            benar = (benar == 1) ? 0 : 1;
    }
    printf("%d\n", benar);
    return 0;
}