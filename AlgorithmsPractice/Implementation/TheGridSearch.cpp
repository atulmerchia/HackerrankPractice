#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int grows, gcols; cin >> grows >> gcols;
        vector<string> g(grows);
        for(string & s : g) cin >> s;

        int prows, pcols; cin >> prows >> pcols;
        vector<string> p(prows);
        for(string & s : p) cin >> s;

        for(int i = 0; i <= grows - prows; i++){
            int index = g[i].find(p[0]);
            while(index != -1){
                bool found = true;
                for(int j = 1; found && j < prows; j++)
                    if(g[i+j].substr(index, pcols) != p[j])
                        found = false;
                if(found){
                    cout << "YES\n";
                    goto end;
                }
                else
                    index = g[i].find(p[0], index + 1);
            }
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
