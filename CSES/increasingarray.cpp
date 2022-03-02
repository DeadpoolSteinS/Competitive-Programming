#include <cstdio>
#define ull unsigned long long
using namespace std;

int main(){
    ull n, increase = 0, x, m = 0;
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &x);
        (m > x) ? increase += m-x : m = x;
    }
    printf("%lld\n", increase);
    return 0;
}