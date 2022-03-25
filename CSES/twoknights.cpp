#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ull unsigned long long
using namespace std;

void scan(ull &angka)
{
    angka = 0; bool negative = false; char input = gc();
    while((input < '0') || (input > '9'))
    {
        if(input == '-') negative = true;
        input = gc();
    }
    while(input >= '0' && input <= '9')
    {
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if(negative) angka = -angka;
}

void print(ull angka)
{
    char number[20]; short i = 0;
    if(angka == 0)
    {
        pc('0');
        return;
    }
    while(angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while(i--) pc(number[i]);
}

int main()
{
    ull n; scan(n);
    for(int i = 1; i <= n; i++)
    {
        // total cell of board
        ull board = i*i;
        // total all place two knights
        ull total = board*(board-1)/2;
        // total attacked place two knights
        ull attack = 4*(i-1)*(i-2);
        print(total-attack); pc('\n');
    }
    return 0;
}