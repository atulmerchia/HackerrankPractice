#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> s(n);
    vector<int> counts(k, 0);
    for(int & i : s) cin >> i;

    for(int i : s) counts[i % k]++;

    int res = 0;
    if(counts[0]) res++;
    for(int i = 1; i < k/2.0; i++)
        res += max(counts[i], counts[k-i]);
    if(k % 2 == 0 && counts[k/2])
        res++;
    cout << res;

    return 0;
}
