#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#define ll unsigned long long
using namespace std;

ll powermod(ll a, ll b, ll c){
    a %= c;
    if(a == 0) return 0;
    ll result = 1;
    while(b > 0){
        if(b & 1) result = (result * a) % c;
        b = b>>1;
        a = (a*a) % c;
    }
    return result;
}

ll solve(vector <ll> n, ll a){
    ll result = n[0] % a;
    for(int i = 1; i < n.size()-1; i++){
        result = powermod(result, n[i], a);
    }
    return result;
}

int main(){
    string a;
    while(getline(cin, a)){
        stringstream ss; ll s;
        vector <ll> n;
        ss << a;
        while(ss >> s) n.push_back(s);
        cout << solve(n, s) << endl;
    }
    return 0;
}