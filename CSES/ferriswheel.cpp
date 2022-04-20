#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
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

int main()
{
    int n, x, gondola = 0;
    scan(n);
    scan(x);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scan(arr[i]);
    }
    sort(arr, arr + n);

    for (int i = n - 1, j = 0; i >= j; i--)
    {
        if (arr[i] + arr[j] <= x)
            j++;
        gondola++;
    }

    print(gondola);
    pc('\n');
    return 0;
}