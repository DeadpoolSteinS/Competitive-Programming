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
    int n, x;
    scan(n);
    scan(x);
    pair<int, int> arr[n];

    for (int i = 0; i < n; i++)
    {
        scan(arr[i].first);
        arr[i].second = i + 1;
    }
    sort(arr, arr + n);

    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr[i].first + arr[j].first < x)
            i++;
        else if (arr[i].first + arr[j].first > x)
            j--;
        else
        {
            print(arr[i].second);
            pc(' ');
            print(arr[j].second);
            pc('\n');
            return 0;
        }
    }

    pc('I');
    pc('M');
    pc('P');
    pc('O');
    pc('S');
    pc('S');
    pc('I');
    pc('B');
    pc('L');
    pc('E');
    pc('\n');
    return 0;
}