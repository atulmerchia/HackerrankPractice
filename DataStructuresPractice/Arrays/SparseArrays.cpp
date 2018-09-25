#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s;

    map<string, int> m;
    while(n--){
        cin >> s;
        m[s]++;
    }
    cin >> n;
    while(n--){
        cin >> s;
        cout << m[s] << endl;
    }

    return 0;
}
