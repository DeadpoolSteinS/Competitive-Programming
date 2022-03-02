#include <iostream>
using namespace std;

int main(){
    long long n, a, ganjil = 0, genap = 0;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> a;
        if(i%2 == 1)
            ganjil += a;
        else
            genap += a;
    }
    if(n == 2)
        cout << ganjil-genap << endl;
    else
        cout << max(ganjil, genap) - min(ganjil, genap) << endl;
    return 0;
}