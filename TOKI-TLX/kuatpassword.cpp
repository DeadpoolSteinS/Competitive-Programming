#include <cstdio>
#include <cstring>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    bool besar = 0, kecil = 0, angka = 0, lain = 0;
    char word[22];
    int abjad = 0;
    scanf("%s", word);
    for(int i = 0; i < strlen(word); i++){
        if(word[i] >= 'A' && word[i] <= 'Z'){
            besar = 1;
            abjad++;
        }
        else if(word[i] >= 'a' && word[i] <= 'z'){
            kecil = 1;
            abjad++;
        }
        else if(word[i] >= '0' && word[i] <= '9')
            angka = 1;
        else
            lain = 1;
    }
    if(besar == 1 && kecil == 1 && angka == 1 && lain == 1 && strlen(word) >= 8)
        printf("Kuat\n");
    else if(abjad > 12)
        printf("AgakKuat\n");
    else
        printf("Lemah\n");
    return 0;
}