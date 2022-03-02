#include <cstdio>
#include <vector>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    vector <int> arr;
    int n, h, a;
    scan(n); scan(h);
    while(n--){
        scan(a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int sisa = h % arr[arr.size()-1];
    int total = h - sisa;
    if(sisa > 0)
        total += arr[lower_bound(arr.begin(), arr.end(), sisa) - arr.begin()];
    printf("%d\n", total);
    return 0;
}