#include <iostream>
#define pc putchar_unlocked
using namespace std;

int main(){
    string n; char unix;
    cin >> n;

    // total each character A-Z on string
    int sum[26] = {}, odd = 0;
    for(auto m : n) sum[m - 'A']++;

    // check odd sum for A-Z
    for(int i = 0; i < 26; i++){
        if(sum[i] & 1){
            unix = i+'A';
            odd++;
        }
    }

    // odd sum more than 1 character
    if(odd > 1) printf("NO SOLUTION\n");

    else{
        // show half and half char on string
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < (int)sum[i]/2; j++) pc(i+'A');
        }
        if(odd == 1) pc(unix);
        for(int i = 25; i >= 0; i--){
            for(int j = 0; j < (int)sum[i]/2; j++) pc(i+'A');
        }
        printf("\n");
    }
    return 0;
}