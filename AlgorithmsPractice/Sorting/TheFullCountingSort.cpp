#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> vec(100);

    int n;
    cin >> n;

    int x;
    string s;
    for(int i = 0; i < n; i++){
        cin >> x;
        cin >> s;
        if(i < n/2) s = "-";
        vec[x] += s + " ";
    }

    for(string s : vec) cout << s;
}
