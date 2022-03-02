#include <iostream>
using namespace std;

int main(){
    long long n, k, x = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        if(x > 0 && x % k == 0)
            x *= 2;
        else
            x++;
    }
    cout << x << endl;
    return 0;
}