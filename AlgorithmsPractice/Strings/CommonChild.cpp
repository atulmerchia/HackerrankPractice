#include <bits/stdc++.h>

using namespace std;
int main(){
    string s1, s2; cin >> s1 >> s2;
    int len = s1.length();

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
        }
    }

    cout << arr[n][n];
    return 0;
}
