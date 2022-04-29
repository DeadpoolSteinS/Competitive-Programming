#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, minimal = 1e9;
    cin >> n >> m;
    int total = n + m;
    int obat[n + m] = {}, a[total], b[total];

    // input tingkat kepahitan
    for (int i = 0; i < total; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // input tingkat kepahitan sekaligus set array obat
    for (int i = n; i < total; i++)
    {
        cin >> b[i];
        obat[i] = 1;
    }

    // permutasi array obat sebagai pilahan pak dan ibu
    do
    {
        int option = 0;
        for (int i = 0; i < total; i++)
        {
            if (obat[i] == 1)
                option += b[i];
            else
                option += a[i];
        }
        if (option < minimal)
            minimal = option;
    } while (next_permutation(obat, obat + total));

    cout << minimal << endl;
    return 0;
}