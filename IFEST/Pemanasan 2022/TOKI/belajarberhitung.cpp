#include <cstdio>
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

int minimal = 1e9, maksimal = 0;

void solve()
{
    int l, r;
    scan(l);
    scan(r);
    if (l < minimal)
        minimal = l;
    if (r > maksimal)
        maksimal = r;
}

signed main()
{
    int n;
    scan(n);
    while (n--)
    {
        solve();
    }
    int jumlah = maksimal - minimal + 1;
    if (jumlah & 1)
        print((2 * minimal + jumlah - 1) / 2 * jumlah);
    else
        print(jumlah / 2 * (2 * minimal + jumlah - 1));
    pc('\n');
    return 0;
}