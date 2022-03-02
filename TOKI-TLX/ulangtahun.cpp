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
    int n, q;
    scan(n); scan(q);
    char name[n][16], number[n][8];
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        scanf("%s", number[i]);
    }
    while(q--){
        char search[16];
        scanf("%s", search);
        int left = 0, right = n, middle;
        while(left <= right){
            middle = (left+right)/2;
            if(strcmp(search, name[middle]) == 0)
                break;
            else if(strcmp(search, name[middle]) > 0)
                left = middle+1;
            else
                right = middle-1;
        }
        printf("%s\n", number[middle]);
    }
    return 0;
}