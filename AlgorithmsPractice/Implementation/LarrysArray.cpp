#include <bits/stdc++.h>
#include<cstring>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        int * a = new int[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        bool * sorted = new bool[n];
        memset(sorted, false, n);

        bool valid = true;
        for(int i = 0; i < n; i++){
            if(sorted[i]) continue;

            int j = i;
            do{
                valid = !valid;
                sorted[j] = true;
                j = a[j]-1;
            }while(!sorted[j]);
            valid = !valid;
        }

        cout << (valid ? "YES\n" : "NO\n");
        delete [] a;
        delete [] sorted;
    }

    return 0;
}
