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
    int n, a, index = 0, nol = 0;
    scan(n);
    int arr[n];
    while(n--){
        scan(a);
        if(a < 0)
            printf("%d\n", a);
        else if(a == 0)
            nol++;
        else{
            arr[index] = a;
            index++;
        }
    }
    for(int i = 0; i < nol; i++)
        printf("0\n");
    for(int i = 0; i < index; i++)
        printf("%d\n", arr[i]);
    return 0;
}