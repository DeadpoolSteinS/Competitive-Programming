#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;

void scan(int &angka)
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

void print(int angka)
{
    char number[10]; short i = 0;
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
    int n; scan(n);
    if(n == 2 || n == 3)
    {
        pc('N'); pc('O'); pc(' ');
        pc('S'); pc('O'); pc('L'); pc('U'); pc('T'); pc('I'); pc('O'); pc('N'); pc('\n');
    }
    else
    {
        for(int i = 2; i <= n; i+=2)
        {
            print(i); pc(' ');
        }
        for(int i = 1; i <= n; i+=2)
        {
            print(i); pc(' ');
        }
        print('\n');
    }
    return 0;
}