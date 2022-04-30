#include <cstdio>
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
    int t;
    scan(t);
    while (t--)
    {
        int n, ada = 0;
        scan(n);
        int arr[n] = {};
        while (n--)
        {
            int a;
            scan(a);
            arr[a - 1]++;
            if (arr[a - 1] >= 3 && !ada)
            {
                print(a);
                ada = 1;
            }
        }
        if (!ada)
            print(-1);
        pc('\n');
    }
    return 0;
}