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

void solve(int n, char from, char dist, char to)
{
    if(n == 1)
    {
        pc(from); pc(' '); pc(to); pc('\n');
    }
    else
    {
        solve(n-1, from, to, dist);
        pc(from); pc(' '); pc(to); pc('\n');
        solve(n-1, dist, from, to);
    }
}

int main()
{
    int n; scan(n);
    print((1 << n) - 1); pc('\n');
    solve(n, '1', '2', '3');
    return 0;
}