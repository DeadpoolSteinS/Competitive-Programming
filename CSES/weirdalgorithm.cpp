#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long
using namespace std;

void scan(ll &angka)
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

void print(ll angka)
{
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
    ll n; scan(n);
    while(n != 1){
        print(n); pc(' ');
        if(n & 1) n = n*3+1;
        else n /= 2;
    }
    pc('1'); pc('\n');
    return 0;
}