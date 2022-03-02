#include <cstdio>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    while(n--){
        long long a, b, total;
        scanf("%lld%lld", &a, &b);
        if(b == 0)
            total = 0;
        else if((b-1)%4 == 0)
            total = -1 * ((b-1)/4 * 4 + 1);
        else if((b+1)%4 == 0)
            total = (b+1)/4 * 4;
        else if((b-2)%4 == 0)
            total = 1;
        else
            total = -1;
        if(a%2 == 0)
            printf("%lld\n", a+total);
        else
            printf("%lld\n", a-total);
    }
    return 0;
}