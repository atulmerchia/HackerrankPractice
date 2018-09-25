#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> solve(string s){
    int len = 1, lev = 0, end = s.length() - 1;

    vector<pair<int, string>> res;
    while (end >= 0) {
        int beg = end - len + 1;
        if(beg < 0) beg = 0;
        int firstNumber = -1;
        for(int i = beg; i <= end; i++)
            if (s[i] != '0') {
                firstNumber = i;
                break;
            }
        if (firstNumber != -1)
            res.push_back(make_pair(lev, s.substr(firstNumber, end - firstNumber + 1)));

        end = beg - 1;
        if(lev) len *= 2;
        lev++;
    }
    return res;
}

int main() {
    string l, r; cin >> l >> r;
    int llen = l.length(), rlen = r.length();
    l.insert(l.begin(), rlen - llen, '0');

    for(int i = rlen - 1; i >= 0; i--)
        if(l[i] != '0'){
            l[i]--;
            break;
        }
        else
            l[i] = '9';

    int ignore = 0;
    while(ignore < rlen && l[ignore] == r[ignore])
        ignore++;

    int zeroOut = (ignore < rlen);
    while(rlen - zeroOut > ignore)
        zeroOut *= 2;
    zeroOut /= 2;

    string mid; mid.resize(rlen, '0');
    for(int i = 0; i < rlen - zeroOut; i++){
        mid[i] = r[i];
        r[i] = '0';
    }

    int borrow = 0;
    for(int i = rlen - 1; i >= 0; i--){
        mid[i] -= borrow + l[i];
        borrow = 0;
        if(mid[i] < 0){
            borrow++;
            mid[i] += 10;
        }
        mid[i] += '0';
    }

    auto firstHalf = solve(mid), secondHalf = solve(r);
    cout << firstHalf.size() + secondHalf.size() << endl;
    for(auto p : firstHalf)
        cout << p.first << " " << p.second << endl;
    for(auto it = secondHalf.rbegin(); it != secondHalf.rend(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}
