#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector <int> arr;
    int n, x, totalb = 0, totalh = 0;
    cin >> n;
    int a[n], b[n], h[n];
    for(int i = 0; i < n; i++){
        cin >> b[i] >> h[i];
        a[i] = i+1;
    }
    cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((double)h[i]/b[i] < (double)h[j]/b[j]){
                swap(a[i], a[j]);
                swap(h[i], h[j]);
                swap(b[i], b[j]);
                // cout << i << "-" << j << endl;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(totalb + b[i] > x){
            continue;
        }
        totalb += b[i];
        totalh += h[i];
        arr.push_back(a[i]);
        // cout << b[i] << "-" << h[i] << endl;
    }
    sort(arr.begin(), arr.end());
    int banyak = arr.size();
    for(int i = 0; i < banyak; i++){
        cout << arr[i];
        if(i < banyak-1)
            cout << " ";
    }
    cout << endl;
    cout << totalb << endl << totalh << endl;
    return 0;
}
