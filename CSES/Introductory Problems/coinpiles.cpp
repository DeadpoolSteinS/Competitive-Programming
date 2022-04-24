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

int main()
{
    int t, a, b;
    scan(t);
    while(t--)
    {
        scan(a); scan(b);
        if((a+b)%3 != 0 || a > b*2 || b > a*2){ pc('N'); pc('O'); pc('\n'); }
        else{ pc('Y'); pc('E'); pc('S'); pc('\n'); }
    }
    return 0;
}