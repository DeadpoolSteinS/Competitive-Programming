#include <cstdio>
#include <algorithm>
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
    int n, cost = 0;
    scan(n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scan(arr[i]);
    nth_element(arr, arr + (n / 2), arr + n);

    for (int i = 0; i < n; i++)
        cost += abs(arr[i] - arr[(int)n / 2]);

    print(cost);
    pc('\n');
    return 0;
}