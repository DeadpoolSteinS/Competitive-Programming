#include <iostream>
#define pc putchar_unlocked
using namespace std;

int main(){
    string n; char unix;
    cin >> n;

    // total each character A-Z on string
    int sum[26] = {}, odd = 0;
    for(char a : n) sum[a - 'A']++;

    // check odd sum for A-Z
    for(int i = 0; i < 26; i++)
    {
        if(sum[i] & 1)
        {
            unix = i+'A';
            odd++;
        }
    }

    // odd sum more than 1 character
    if(odd > 1)
    {
        pc('N'); pc('O'); pc(' ');
        pc('S'); pc('O'); pc('L'); pc('U'); pc('T'); pc('I'); pc('O'); pc('N'); pc('\n');
        return 0;
    }
    else
    {
        // show half and half char on string
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < (int)sum[i]/2; j++) pc(i+'A');
        }
        if(odd == 1) pc(unix);
        for(int i = 25; i >= 0; i--)
        {
            for(int j = 0; j < (int)sum[i]/2; j++) pc(i+'A');
        }
        pc('\n');
    }
    return 0;
}