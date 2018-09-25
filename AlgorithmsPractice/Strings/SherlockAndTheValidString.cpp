#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    vector<int> vec(26, 0);
    for(char c : s)
        vec[c - 'a']++;

    map<int, int> nums;
    int destroy = 0;

    for(int i : vec)
        if(i != 0){
            nums[i]++;
        }

    if(nums.size() > 2)
        cout << "NO";
    else if(nums.size() <= 1)
        cout << "YES";
    else if(nums.begin()->first == 1 && nums.begin()->second == 1)
        cout << "YES";
    else if(nums.rbegin()->first == nums.begin()->first + 1
       && nums.rbegin()->second == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
