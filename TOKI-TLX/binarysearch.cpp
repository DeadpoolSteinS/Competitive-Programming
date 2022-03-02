#include <cstdio>
#define gc getchar_unlocked
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
    int n, m, a;
    scan(n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scan(arr[i]);
    scan(m);
    while(m--){
        scan(a);
        int left = 0, right = n, middle;
        while(left < right){
            middle = (left + right) / 2;
            if(arr[middle] < a)
                left = middle+1;
            else
                right = middle;
        }
        if(arr[left] == a)
            printf("%d\n", left);
        else
            printf("-1\n");
    }
    return 0;
}