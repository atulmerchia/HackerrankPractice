#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cap = n/4;

    string gene;
    cin >> gene;

    map<char, int> count;

    int right = n - 1;
    while(right >= 0 && count[gene[right]] != cap)
        count[gene[right--]]++;
    right++;

    int ans = right;
    for(int left = 0; right < n; right++){
        count[gene[right]]--;
        while(left < n && count[gene[left]] != cap)
            count[gene[left++]]++;
        ans = min(ans, right - left);
    }

    cout << ans + 1;

    return 0;
}
