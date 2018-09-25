#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull mod = 1e9 + 7;

ull powmod (ull x, ull y){
    ull res = 1;
    while(y){
        if(y & 1)
            res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

int main(){
    string s; cin >> s;
    int n = s.length();

    int count [n+1][26];
    ull fact [n/2 + 1];
    ull inv [n/2 + 1];

    memset(count, 0, 26);

    fact[0] = 1;
    inv[0] = 1;

    for(int i = 1; i <= n/2; i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i] = powmod(fact[i], mod - 2);
    }

    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < 26; j++)
            count[i+1][j] = count[i][j];
        count[i+1][s[i]-'a']++;
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        int len = 0, odds = 0;
        ull res = 1;
        for(int i = 0; i < 26; i++){
            int occurrences = count[r][i] - count[l-1][i];
            len += occurrences/2;
            if(occurrences & 1)
                odds++;
            res = res * inv[occurrences/2] % mod;
        }
        res = res * fact[len] % mod;
        if(odds)
            res = res * odds % mod;
        cout << res << endl;
    }
}
