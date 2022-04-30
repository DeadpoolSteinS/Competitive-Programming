#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[26] = {}, total = n;
    while (n--)
    {
        char c;
        cin >> c;
        arr[c - 65]++;
    }
    while (m--)
    {
        char c;
        string re;
        cin >> c >> re;
        int getLong = arr[c - 65];
        for (int i = 0; i < re.length(); i++)
        {
            arr[re[i] - 65] += getLong;
            if (i > 0)
                total += getLong;
        }
        arr[c - 65] = 0;
    }
    cout << total << endl;
    return 0;
}