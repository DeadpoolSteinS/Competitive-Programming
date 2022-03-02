#include <cstdio>
#define gc getchar_unlocked
using namespace std;

void scan(int &angka){
    angka = 0; bool negative = false; char input = gc();
    while((input < '0') || (input > '9')){
        if(input == '-') negative = true;
        input = gc();
    }
	while(input >= '0' && input <= '9'){
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if(negative) angka = -angka;
}

int main(){
    int t, n, a;
    scan(t);
    while(t--){
        int arr[1000] = {}, sisa = 5, total = 0;
        scan(n);
        while(n--){
            scan(a);
            if(a > 0)
                arr[a-1]++;
        }
        for(int i = 999; i >= 0; i--){
            if(arr[i] > 0){
                if(arr[i] > sisa){
                    total += (sisa * (i+1));
                    sisa = 0;
                }
                else{
                    total += (arr[i] * (i+1));
                    sisa -= arr[i];
                }
            }
            if(sisa == 0)
                break;
        }
        printf("%d\n", total);
    }
    return 0;
}