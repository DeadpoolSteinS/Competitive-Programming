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
    int N, total = 2;
    bool pangkat = false;
    scan(N);
    for(int i = 1; i*i <= N; i++){
        if(N%i == 0){
            if(i*i == N)
                pangkat = true;
            total++;
        }
    }
    if(total == 5 && pangkat)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}