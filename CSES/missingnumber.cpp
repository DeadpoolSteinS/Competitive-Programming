#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    int arr[n] = {};
    for(int i = 0; i < n-1; i++){
        scanf("%d", &m);
        arr[m-1] = 1;
    }
    int x = distance(arr, find(arr, arr+n, 0));
    printf("%d\n", x+1);
    return 0;
}