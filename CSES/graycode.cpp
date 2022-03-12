#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;

void scan(int &angka)
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

int main()
{
    int n; scan(n);

    // total output
    int x = 1 << n;
    for(int i = 0; i < x; i++)
    {
        // 0 = 0, 1 = 1, 2 = 3, 3 = 2, 4 = 6
        int m = i ^ (i >> 1);
        for(int j = x >> 1; j != 0; j >>= 1)
        {
            if(j & m) pc('1');
            else pc('0');
        }
        pc('\n');
    }
    return 0;
}