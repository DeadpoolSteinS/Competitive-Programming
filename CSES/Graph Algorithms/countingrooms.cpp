#include <iostream>
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

int n, m;
string area[1000];

void markArea(int a, int b)
{
    area[a][b] = '#';
    if (a - 1 >= 0 && area[a - 1][b] == '.')
        markArea(a - 1, b);
    if (b - 1 >= 0 && area[a][b - 1] == '.')
        markArea(a, b - 1);
    if (a + 1 < n && area[a + 1][b] == '.')
        markArea(a + 1, b);
    if (b + 1 < m && area[a][b + 1] == '.')
        markArea(a, b + 1);
}

signed main()
{
    int rooms = 0;
    scan(n);
    scan(m);

    for (int i = 0; i < n; i++)
        cin >> area[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (area[i][j] == '.')
                markArea(i, j), rooms++;

    print(rooms);
    pc('\n');
    return 0;
}