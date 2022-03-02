#include <iostream>
#define ll long long
using namespace std;

ll solve(ll a, ll b){
    if(a >= b) return 0;
    ll result = 1;
    for(int i = 1; i <= a; i++){
        result = (result * i) % b;
    }
    return result;
}

int main(){
    ll n, m;
    while(cin >> n){
        cin >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}