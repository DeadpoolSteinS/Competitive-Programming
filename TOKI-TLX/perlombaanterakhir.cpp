#include <cstdio>
#include <cstring>
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
    char S[101];
    bool once = false;
    scanf("%s", S);
    for(int i = 0; i < strlen(S); i++){
        if(S[i] == 'O'){
            if(!once)
                once = true;
            else{
                printf("Tidak\n");
                return 0;
            }
        }
    }
    if(once)
        printf("Ya\n");
    else
        printf("Tidak\n");
    return 0;
}