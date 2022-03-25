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
    if(angka == 0)
    {
        pc('0');
        return;
    }
    char number[20]; short i = 0;
    while(angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while(i--) pc(number[i]);
}

int main()
{
    ull n, increase = 0, next, prev = 0;
    scan(n);
    while(n--)
    {
        scan(next);
        (prev > next) ? increase += prev-next : prev = next;
    }
    print(increase); pc('\n');
    return 0;
}