#include <iostream>
#include <cstring>
using namespace std;

int main(){
    long long n, k, total = 0, now = 0;
    cin >> n >> k;
    string biner;
    cin >> biner;
    long long awal = 0, akhir = n-1, r = 0, s = 0;
    while(biner[awal] == '0' && awal <= akhir)
        awal++;

    while(biner[akhir] == '1' && akhir >= awal)
        akhir--;
    
    for(int i = awal; i <= akhir; i++){
        if(biner[i] == '1')
            r++;
        else
            s++;
    }
    if(r <= s){
        while(k > 0 && awal <= akhir){
            if(biner[awal] == '1')
                k--;
            awal++;
        }
    }
    else{
        while(k > 0 && akhir >= awal){
            if(biner[akhir] == '0')
                k--;
            akhir--;
        }
    }
    for(int i = awal; i <= akhir; i++){
        if(biner[i] == '0')
            total += now;
        else
            now++;
    }
    cout << total << endl;
    return 0;
}