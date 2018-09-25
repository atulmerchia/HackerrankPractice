#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<bool> changed(n, false);;
    int left = 0, right = n - 1;

    int changes = 0;
    while(left < right){
        if(s[left] < s[right]){
            s[left] = s[right];
            changed[left] = true;
            changes++;
        }
        else if(s[left] > s[right]){
            s[right] = s[left];
            changed[right] = true;
            changes++;
        }
        left++;
        right--;
    }

    if(changes > k){
        cout << -1;
        return 0;
    }

    if(changes == k){
        cout << s;
        return 0;
    }

    left = 0, right = n - 1;
    while(left <= right){
        int c = 0;
        if(!changed[left] && s[left] != '9')
            c++;

        if(left != right && !changed[right] && s[right] != '9')
            c++;

        if(changes + c > k){
            left++;
            right--;
            continue;
        }

        changes += c;
        s[left++] = '9';
        s[right--] = '9';
    }

    cout << s;
}
