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
    ull t; scan(t);
    while(t--)
    {
        ull x, y; scan(x); scan(y);
        if(x >= y)
        {
            if(x & 1) print((x-1)*(x-1)+y);
            else print(x*x-(y-1));
        }
        else
        {
            if(y & 1) print(y*y-(x-1));
            else print((y-1)*(y-1)+x);
        }
        pc('\n');
    }
    return 0;
}