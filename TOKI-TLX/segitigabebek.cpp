#include <cstdio>
#include <cmath>
#define gc getchar_unlocked
using namespace std;

void scan(int &angka){
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

int main(){
    int n, total, minim = 1e9;
    bool sama = false;
    scan(n);
    int arr[n][2];
    for(int i = 0; i < n; i++){
        scan(arr[i][0]);
        scan(arr[i][1]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                total = abs(arr[i][0]*arr[j][1] + arr[j][0]*arr[k][1] + arr[k][0]*arr[i][1] - 
                            arr[i][1]*arr[j][0] - arr[j][1]*arr[k][0] - arr[k][1]*arr[i][0]);
                if(minim > total && total > 0){
                    minim = total;
                    sama = false;
                }
                else if(minim == total)
                    sama = true;
            }
        }
    }
    double akhir = minim;
    if(minim != 1e9 && !sama)
        printf("%.2lf\n", akhir/2);
    else
        printf("-1.00\n");
    return 0;
}