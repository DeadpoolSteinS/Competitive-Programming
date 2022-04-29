#include <cstdio>
#include <unordered_set>
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
    int n, maksimum = 0;
    scan(n);
    int k[n];

    for (int i = 0; i < n; i++)
        scan(k[i]);

    unordered_set<int> arr;
    arr.reserve(n);

    for (int i = 0, b = 0; i < n; i++, b++)
    {
        // if exist delete in front
        while (arr.find(k[i]) != arr.end())
            arr.erase(k[i - (b--)]);
        arr.insert(k[i]);

        // get maksimum sequence
        if (b > maksimum)
            maksimum = b;
    }

    print(maksimum + 1);
    pc('\n');
    return 0;
}