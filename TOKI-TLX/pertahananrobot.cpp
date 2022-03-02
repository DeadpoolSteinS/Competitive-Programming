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
    char move[105];
    int x = 0, y = 0;
    scanf("%s", move);
    for(int i = 0; i < strlen(move); i++){
        if(move[i] == 'R')
            x++;
        else if(move[i] == 'L')
            x--;
        else if(move[i] == 'U')
            y++;
        else if(move[i] == 'D')
            y--;
    }
    printf("%d %d\n", x, y);
    return 0;
}