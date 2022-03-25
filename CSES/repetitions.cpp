#include <cstdio>
#include <cstring>
#include <algorithm>
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
    while(angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while(i--) pc(number[i]);
}

const int MAX = 1e6+7;

int main()
{
    char n[MAX]; scanf("%s", n);
    char prev = n[0];
    int total = 0, counter = 1;
    for(int i = 1; i < strlen(n); i++)
    {
        if(n[i] != prev)
        {
            total = max(total, counter);
            counter = 1;
            prev = n[i];
        }
        else counter++;
    }
    total = max(total, counter);
    print(total); pc('\n');
    return 0;
}