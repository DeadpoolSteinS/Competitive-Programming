#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long
using namespace std;

void scan(ll &angka)
{
    angka = 0; bool negative = false; char input = gc();
    while((input < '0') || (input > '9'))
    {
        if(input == '-') negative = true;
        input = gc();
    }
    while(input >= '0' && input <= '9')
    {
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if(negative) angka = -angka;
}

void print(ll angka)
{
    char number[20]; short i = 0;
    if(angka == 0)
    {
        pc('0');
        return;
    }
    while(angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while(i--) pc(number[i]);
}

ll n, p[20], total;

// get minimum difference
ll solve(ll x, ll y)
{
    // last number
    if(y == n-1) return abs(total - 2*x);
    // recursive use and not use next number
    return min(solve(x+p[y], y+1), solve(x, y+1));
}

int main()
{
    scan(n);
    // input n number and total all
    for(ll i = 0; i < n; i++)
    {
        scan(p[i]);
        total += p[i];
    }
    print(solve(0, 0)); pc('\n');
    return 0;
}