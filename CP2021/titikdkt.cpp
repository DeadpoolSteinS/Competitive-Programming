#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){
    ll x, y, a, b, c = 1e15+7, fx, fy;
    cin >> x >> y;
    while(cin >> a){
        cin >> b;
        ll z = pow(abs(x-a), 2) + pow(abs(y-b), 2);
        if(z < c){
            fx = a;
            fy = b;
            c = z;
        }
    }
    cout << fx << " " << fy << endl;
    return 0;
}