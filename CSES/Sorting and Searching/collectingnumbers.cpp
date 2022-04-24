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
        return;
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
    int n, rounds = 1;
    scan(n);
    bool arr[n + 1] = {};
    arr[0] = true;

    for (int i = 1; i <= n; i++)
    {
        int x;
        scan(x);
        if (!arr[x - 1])
            rounds++;
        arr[x] = true;
    }

    print(rounds);
    pc('\n');
    return 0;
}