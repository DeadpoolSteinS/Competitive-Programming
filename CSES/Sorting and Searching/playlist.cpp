#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
// #define gc getchar
// #define pc putchar
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

const int MAX = 1e3;

signed main()
{
    int n, maksimal = 0;
    scan(n);
    int arr[n], marked[MAX] = {};

    for (int i = 0; i < n; i++)
        scan(arr[i]);

    for (int i = 0, j = 0; i < n; i++)
    {
        while (marked[arr[i]])
            marked[arr[j++]] = 0;
        marked[arr[i]] = true;
        maksimal = max(maksimal, i - j + 1);
    }

    print(maksimal);
    pc('\n');
    return 0;
}