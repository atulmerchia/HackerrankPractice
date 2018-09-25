#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        if(k == 0){
            for(int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        }

        if(n % (2*k)){
            cout << "-1\n";
            continue;
        }

        int sign = 1;
        for(int i = 1; i <= n; i++){
            cout << i + sign * k << " ";
            if(i % k == 0)
                sign *= -1;
        }
        cout << endl;
    }
    return 0;
}
