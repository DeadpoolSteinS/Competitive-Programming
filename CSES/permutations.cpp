#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n == 2 || n == 3) printf("NO SOLUTION\n");
    else{
        for(int i = 2; i <= n; i+=2) printf("%d ", i);
        for(int i = 1; i <= n; i+=2){
            printf("%d", i);
            if((i == n && (n&1)) || i == n-1 && !(n&1)) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}