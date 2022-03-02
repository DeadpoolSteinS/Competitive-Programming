#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e6+7;

int main(){
    char n[MAX];
    int begin = 0, maxdna = 0;
    scanf("%s", n);
    for(int i = 1; i <= strlen(n); i++){
        if(i == strlen(n) || n[i] != n[i-1]){
            maxdna = max(maxdna, i-begin);
            begin = i;
        }
    }
    printf("%d\n", maxdna);
    return 0;
}