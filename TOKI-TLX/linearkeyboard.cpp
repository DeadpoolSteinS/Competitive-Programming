#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int total = 0, kiri;
        char panduan[100], yangCari[100];
        scanf("%s", panduan);
        scanf("%s", yangCari);
        for(int i = 0; i < strlen(yangCari); i++){
            for(int j = 0; j < strlen(panduan); j++){
                if(yangCari[i] == panduan[j]){
                    if(i == 0)
                        kiri = j;
                    else{
                        total += abs(j-kiri);
                        kiri = j;
                    }
                    break;
                }
            }
        }
        printf("%d\n", total);
    }
    return 0;
}