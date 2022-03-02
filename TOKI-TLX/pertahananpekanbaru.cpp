#include <cstdio>
#include <queue>
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
    int n, sd, sm, p, k, l, flag = 0; char sub[50];
    scanf("%s", sub);
    scan(n); scan(sd); scan(sm);
    priority_queue<int, vector<int>, greater<int>> waktu;
    long long total = 0;
    for(int i = 1; i < n; i++){
        scan(p); scan(k); scan(l);
        if(flag == 0){
            while(sd < p && !waktu.empty()){
                total += waktu.top();
                sd++;
                waktu.pop();
            }
            if(sd < p && waktu.empty()){
                flag = 1;
                continue;
            }
            if(k < l){
                total += k;
                waktu.push(l-k);
            }
            else{
                total += l;
                sd++;
            }
        }
    }
    if(flag == 0){
        while(sd < sm && !waktu.empty()){
            total += waktu.top();
            sd++;
            waktu.pop();
        }
        if(sd < sm && waktu.empty())
            flag = 1;
    }
    if(flag == 0)
        printf("%lld\n", total);
    else
        printf("-1\n");
    return 0;
}