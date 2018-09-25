#include <bits/stdc++.h>
#include <memory.h>

using namespace std;

int main(){
    string s; cin >> s;
    int MOD = 1e9 + 7;

    long arr [26][26][4];

    memset(arr, 0, sizeof arr);

    for(char c : s){
        int i = c - 'a';
        for(int j = 0; j < 26; j++){
            arr[i][j][3] += arr[i][j][2] % MOD;
            arr[j][i][2] += arr[j][i][1] % MOD;
            arr[j][i][1] += arr[j][i][0] % MOD;
            arr[i][j][0]++;
        }
    }

    long res = 0;
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            res = (res + arr[i][j][3]) % MOD;
    cout << res;
    return 0;
}
