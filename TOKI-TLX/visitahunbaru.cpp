#include <cstdio>
#include <cstring>
#include <cctype>
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
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);
    for(int i = 0; i < strlen(s); i++){
        if(tolower(s[i]) != tolower(t[i])){
            printf("x_x\n");
            return 0;
        }
    }
    if(strlen(s) == strlen(t))
        printf("20/20\n");
    return 0;
}