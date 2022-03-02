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
    int n;
    scan(n);
    
    // sum total is odd
    if((int)(n+1)/2 & 1) printf("NO\n");
    else{
        printf("YES\n");
        // odd n
        if(n & 1){
            printf("%d\n", n/2);
            for(int i = 4; i <= (n+9)/4; i++){
                printf("%d %d", i, n-i+4);
                if(i < (n+9)/4) printf(" ");
            }
            if(n > 3) printf(" ");
            printf("3\n");
            printf("%d\n", (n+1)/2);
            for(int i = (n+13)/4; i <= (n+3)/2; i++){
                printf("%d %d", i, n-i+4);
                if(i < (n+3)/2) printf(" ");
            }
            if(n > 3) printf(" ");
            printf("1 2\n");
        }
        // even n
        else{
            printf("%d\n", n/2);
            for(int i = 1; i <= n/4; i++){
                printf("%d %d", i, n-i+1);
                if(i < n/4) printf(" ");
            }
            printf("\n");
            printf("%d\n", n/2);
            for(int i = n/4+1; i <= n/2; i++){
                printf("%d %d", i, n-i+1);
                if(i < n/2) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}