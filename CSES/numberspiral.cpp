#include <cstdio>
#define gc getchar_unlocked
#define ull unsigned long long
using namespace std;

void scan(ull &angka){
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
    ull t;
    scan(t);
    while(t--){
        ull x, y;
        scan(x); scan(y);
        if(x >= y){
            if(x & 1) printf("%lld", (x-1)*(x-1)+y);
            else printf("%lld", x*x-(y-1));
        }
        else{
            if(y & 1) printf("%lld", y*y-(x-1));
            else printf("%lld", (y-1)*(y-1)+x);
        }
        printf("\n");
    }
    return 0;
}