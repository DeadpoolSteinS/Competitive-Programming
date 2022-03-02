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
    int b, p, l;
    scan(b); scan(p); scan(l);
    int arr[4][3];
    int one = 0, two = 0;
    if(b <= 10 && p <= 40 && l <= 90)
        printf("S\n");
    else if(b <= 14 && p <= 60 && l <= 120)
        printf("M\n");
    else if(b <= 18 && p <= 80 && l <= 180)
        printf("L\n");
    else
        printf("X\n");
    return 0;
}