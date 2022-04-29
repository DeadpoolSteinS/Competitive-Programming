#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin.ignore(256, '\n');
        string a;
        getline(cin, a);
        cout << a << endl;
    }
    return 0;
}