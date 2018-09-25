#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    set<int> denseScores;
    while(n--){
        int s; cin >> s;
        denseScores.insert(s);
    }

    auto it = denseScores.begin();
    int index = denseScores.size() + 1;
    cin >> n;
    while(n--){
        int s; cin >> s;
        while(it != denseScores.end() && s >= *it){
            it++;
            index--;
        }
        cout << index << endl;
    }
}
