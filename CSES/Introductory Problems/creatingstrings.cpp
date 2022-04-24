#include <iostream>
#include <algorithm>
#include <vector>
#define pc putchar_unlocked
using namespace std;

void print(int angka)
{
    char number[10]; short i = 0;
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

int main()
{
    string n; cin >> n;
    sort(n.begin(), n.end());
    vector<string> arr;

    // make permutations of string n
    do{
        arr.push_back(n);
    } while(next_permutation(n.begin(), n.end()));

    // print total permutations
    print(arr.size()); pc('\n');
    // print permutations
    for(string a : arr)
    {
        for(char c : a) pc(c);
        pc('\n');
    }
    return 0;
}