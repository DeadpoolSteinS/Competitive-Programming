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

const int MAX = 2e5+7;
int ada[MAX];

int main(){
    int n, a;
    bool unique = true, beda = false;
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a);
        if(ada[a] == 1)
            unique = false;
        else{
            if(!beda && i >= 1)
                beda = true;
            ada[a] = 1;
        }
    }
    if(unique)
        printf("%d\n", n);
    else if(beda)
        printf("%d\n", n-1);
    else
        printf("1\n");
    return 0;
}