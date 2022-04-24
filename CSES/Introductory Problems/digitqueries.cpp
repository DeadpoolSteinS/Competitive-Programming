#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long
using namespace std;

void scan(ll &angka)
{
    angka = 0;
    bool negative = false;
    char input = gc();
    while ((input < '0') || (input > '9'))
    {
        if (input == '-')
            negative = true;
        input = gc();
    }
    while (input >= '0' && input <= '9')
    {
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if (negative)
        angka = -angka;
}

void print(ll angka)
{
    char number[10];
    short i = 0;
    if (angka == 0)
    {
        pc('0');
        return;
    }
    while (angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while (i--)
        pc(number[i]);
}

ll digit(ll n, ll i)
{
    return i == 0 ? n % 10 : digit(n / 10, i - 1);
}

int main()
{
    ll q;
    scan(q);
    while (q--)
    {
        // p = lower of largest digit, i = largest digit
        ll k, p = 1, i;
        scan(k);
        for (i = 1; k > p * 9 * i; i++)
        {
            k -= p * 9 * i;
            p *= 10;
        }
        // print(value, digit)
        print(digit(p + (k - 1) / i, i - 1 - (k - 1) % i));
        pc('\n');
    }
    return 0;
}