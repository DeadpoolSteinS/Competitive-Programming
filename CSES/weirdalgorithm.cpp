#include <cstdio>
#define ll long long
using namespace std;

int main(){
    ll n;
    scanf("%lld", &n);
    while(n != 1){
        printf("%lld ", n);
        if(n & 1) n = (ll)n*3+1;
        else n /= 2;
    }
    printf("1\n");
    return 0;
}