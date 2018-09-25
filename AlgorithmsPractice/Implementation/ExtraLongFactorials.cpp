#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
    const int mod = 10000;
    vector<int> res = {1};

    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < res.size(); j++){
            carry += i * res[j];
            res[j] = carry % mod;
            carry /= mod;
        }
        while(carry){
            res.push_back(carry % mod);
            carry /= mod;
        }
    }

    cout << res.back();
    cout << setfill('0');
    for(int i = res.size() - 2; i >= 0; i--)
        cout << setw(4) << res[i];

    return 0;
}
