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

signed main()
{
    int minimal, diskon, maksimal, harga, jumlah;
    scan(minimal);
    scan(diskon);
    scan(maksimal);
    scan(harga);
    scan(jumlah);

    int total = harga * jumlah;
    if (total >= minimal)
    {
        int totalDiskon = diskon * total / 100;
        if (totalDiskon <= maksimal)
            total -= totalDiskon;
        else
            total -= maksimal;
    }

    print(total);
    pc('\n');
    return 0;
}