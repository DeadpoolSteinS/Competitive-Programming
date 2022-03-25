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

const int MAX = 1e9+7;

int main()
{
    int n, total = 1;
    scan(n);
    while(n--) total = (total << 1) % MAX;
    print(total);
    return 0;
}