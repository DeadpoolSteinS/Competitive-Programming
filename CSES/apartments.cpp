#include <cstdio>
#include <algorithm>
#define gc getchar
#define pc putchar
#define ll long long
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
    int n, m, k, total = 0;
    scan(n);
    scan(m);
    scan(k);
    int a[n], b[m];

    for (int i = 0; i < n; i++)
        scan(a[i]);
    sort(a, a + n);
    for (int i = 0; i < m; i++)
        scan(b[i]);
    sort(b, b + m);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] - b[j] <= k && b[j] - a[i] <= k)
        {
            total++;
            j++;
            i++;
        }
        else if (a[i] - b[j] > k)
            j++;
        else
            i++;
    }

    print(total);
    pc('\n');
    return 0;
}