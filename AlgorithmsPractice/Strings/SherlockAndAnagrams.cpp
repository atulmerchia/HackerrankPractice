#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int len = s.length();
        int count [len+1][26];

        for(int &i : count[0]) i = 0;

        for(int i = 0; i < len; i++){
            for(int j = 0; j < 26; j++)
                count[i+1][j] = count[i][j];
            count[i+1][s[i] - 'a']++;
        }

        int ans = 0;

        for(int i = 1; i <= len; i++){
            for(int j = i; j <= len; j++){
                for(int k = j + 1; k <= len; k++){
                    bool yes = true;
                    for(int m = 0; m < 26; m++){
                        if(count[k][m] - count[k-i][m] == count[j][m] - count[j-i][m]) continue;
                        yes = false;
                        break;
                    }
                    if(yes)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
