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
    // n is total output
    int n; scan(n); n = 1 << n;
    for(int i = 0; i < n; i++)
    {
        // get gray code of decimal i
        int gray = i ^ (i >> 1);

        // convert to binary
        for(int j = (n >> 1); j > 0; j >>= 1)
        {
            if(gray & j) pc('1');
            else pc('0');
        }
        pc('\n');
    }
    return 0;
}