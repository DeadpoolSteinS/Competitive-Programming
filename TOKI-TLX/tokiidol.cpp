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
    int a[3], total = 0;
    for(int i = 0; i < 3; i++){
        scan(a[i]);
        if(a[i] < 50){
            printf("Tidak Lolos\n");
            return 0;
        }
        total += a[i];
    }
    if(total >= 200)
        printf("Lolos\n");
    else
        printf("Tidak Lolos\n");
    return 0;
}