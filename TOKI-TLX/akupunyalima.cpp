#include <cstdio>
#include <cmath>
#include <algorithm>
#define gc getchar_unlocked
#define ll long long
using namespace std;

void scan(ll &angka){
    angka = 0; bool negative = false; char input = gc();
    while((input < '0') || (input > '9')){
        if(input == '-') negative = true;
        input = gc();
    }
	while(input >= '0' && input <= '9'){
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if(negative) angka = -angka;
}

bool ans[30], hel[30];
ll bny = 0, byk = 0;

ll cekmin(ll n){
    if(ans[bny])
        bny--;
    ll b = pow(5, bny);
    while(abs(n-b) > abs(n-(b/5)) && b > 0){
        b /= 5;
        bny--;
    }
    return b;
}

int main(){
    ll n, beli = 0, jual = 0;
    scan(n);
    ll a = n;
    while(a > 0){
        a /= 5;
        bny++;
    }
    ll b = 0, m = n;
    while(b < m){
        b += cekmin(n);
        n = m-b;
        ans[bny] = true;
    }
    ll c = n;
    while(c > 0){
        c /= 5;
        byk++;
    }
    ll d = 0, o = n;
    while(n > 0){
        d += cekmin(n);
        n = o-d;
        ans[byk] = true;
        if(n == 0)
            printf("YES\n");
        if(ans[byk]){
            printf("NO\n");
            return 0;
        }
        printf("Beng\n");
    }
    if(n == 0)
        printf("YES\n");
    return 0;
}