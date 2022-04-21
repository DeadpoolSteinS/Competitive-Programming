#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
using namespace std;

void scan(int &angka)
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

void print(int angka)
{
    if (angka == 0)
    {
        pc('0');
        return;
    }
    else if (angka < 0)
    {
        pc('-');
        angka *= -1;
    }

    char number[20];
    short i = 0;
    while (angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while (i--)
        pc(number[i]);
}

signed main()
{
    int n, maximum, now;
    scan(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scan(x);
        if (i == 0)
        {
            maximum = x;
            now = x;
        }
        else
        {
            now = (now + x > x) ? now + x : x;
            maximum = (maximum > now) ? maximum : now;
        }
    }

    print(maximum);
    pc('\n');
    return 0;
}