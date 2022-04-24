#include <cstdio>
#include <algorithm>
// #define gc getchar_unlocked
// #define pc putchar_unlocked
#define gc getchar
#define pc putchar
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

int solve(int n, int alt[])
{
    int rounds = 1;
    bool arr[n + 1] = {};
    arr[0] = true;

    for (int i = 1; i <= n; i++)
    {
        if (!arr[alt[i] - 1])
            rounds++;
        arr[alt[i]] = true;
    }

    return rounds;
}

signed main()
{
    int n, m;
    scan(n);
    scan(m);
    int arr[n + 1], alt[n + 1];

    for (int i = 1; i <= n; i++)
        scan(alt[i]);

    while (m--)
    {
        int a, b;
        scan(a);
        scan(b);
        swap(alt[a], alt[b]);
        print(solve(n, alt));
        pc('\n');
    }
    return 0;
}