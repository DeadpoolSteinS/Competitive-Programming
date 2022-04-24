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
    int n, m, rounds = 1;
    scan(n);
    scan(m);
    int arr[n + 2], alt[n + 1];
    arr[0] = 1;
    arr[n + 1] = n + 1;

    for (int i = 1; i <= n; i++)
    {
        scan(alt[i]);
        arr[alt[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        if (arr[i - 1] > arr[i])
            rounds++;

    while (m--)
    {
        int a, b;
        scan(a);
        scan(b);
        int x = alt[a], y = alt[b];
        swap(alt[a], alt[b]);

        if (arr[x - 1] <= arr[x] && arr[x - 1] > b)
            rounds++;
        if (arr[x - 1] > arr[x] && arr[x - 1] <= b)
            rounds--;
        if (arr[x + 1] >= arr[x] && arr[x + 1] < b)
            rounds++;
        if (arr[x + 1] < arr[x] && arr[x + 1] >= b)
            rounds--;
        arr[x] = b;

        if (arr[y - 1] <= arr[y] && arr[y - 1] > a)
            rounds++;
        if (arr[y - 1] > arr[y] && arr[y - 1] <= a)
            rounds--;
        if (arr[y + 1] >= arr[y] && arr[y + 1] < a)
            rounds++;
        if (arr[y + 1] < arr[y] && arr[y + 1] >= a)
            rounds--;
        arr[y] = a;

        print(rounds);
        pc('\n');
    }
    return 0;
}