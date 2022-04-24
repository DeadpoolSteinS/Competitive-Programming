#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ull unsigned long long
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
    
    // sum total is odd
    if((int)(n+1)/2 & 1)
    {
        pc('N'); pc('O'); pc('\n');
        return 0;
    }
    // odd or even identity
    int k = 1; if(n&1) k = 0;

    pc('Y'); pc('E'); pc('S'); pc('\n');
    for(int i = k; i <= k+1; i++)
    {
        // sum of two sets
        print((n&1) ? n/2+i : n/2); pc('\n');
        for(int j = i; j <= n/2; j += 2)
        {
            if(j > 0){ print(j); pc(' '); }
            print(n-j+k); pc(' ');
        }
        pc('\n');
    }
    return 0;
}