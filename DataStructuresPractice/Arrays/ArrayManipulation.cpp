#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<long> arr (n, 0);
    while(q--){
        int a, b;
        long k;
        cin >> a >> b >> k;
        arr[a-1] += k;
        if(b != n)
            arr[b] -= k;
    }
    long max = arr[0];
    long curr = 0;
    for(int i : arr){
        curr += i;
        if(curr > max)
            max = curr;
    }
    cout << max;
    return 0;
}
