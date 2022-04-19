#include <iostream>
using namespace std;

int langkah = 0, n;

void solve(int m)
{
    if (m == n)
        langkah++;
    else if (m < n)
    {
        solve(m + 1);
        solve(m + 2);
    }
}

int main()
{
    cin >> n;
    solve(1);
    solve(2);
    cout << langkah << endl;
    return 0;
}