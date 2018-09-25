#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;

    while(q--){
        int n; cin >> n;

        vector<int> sizes(n, 0), types(n, 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int x; cin >> x;
                sizes[i] += x;
                types[j] += x;
            }

        sort(sizes.begin(), sizes.end());
        sort(types.begin(), types.end());

        string ans = "Possible";
        for(int i = 0; i < n; i++)
            if(sizes[i] != types[i]){
                ans = "Impossible";
                break;
            }
        cout << ans << endl;
    }

    return 0;
}
