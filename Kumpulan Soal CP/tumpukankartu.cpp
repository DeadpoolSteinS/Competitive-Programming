#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        // index on top
        int kali = (a * b) % n;
        if (kali == 0)
            kali = n;

        for (int i = n; i > 0; i--)
        {
            int x;
            cin >> x;
            if (i == kali)
                cout << x << endl;
        }
    }
    return 0;
}