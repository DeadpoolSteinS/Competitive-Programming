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
    int n, maxCustomers = 0, now = 0;
    scan(n);
    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        scan(a[i]);
        scan(b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0, j = 0; i < n;)
    {
        if (a[i] < b[j])
        {
            maxCustomers = max(maxCustomers, ++now);
            i++;
        }
        else
        {
            now--;
            j++;
        }
    }

    print(maxCustomers);
    pc('\n');
    return 0;
}