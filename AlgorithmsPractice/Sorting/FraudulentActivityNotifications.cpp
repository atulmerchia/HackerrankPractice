#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, d;
    cin >> n >> d;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    deque<int> que(arr.begin(), arr.begin() + d);
    sort(que.begin(), que.end());

    int count = 0;

    for(int i = d; i < n; i++){
        double med = que[d/2];
        if(d % 2 == 0)
            med = (med + que[d/2 - 1]) / 2;
        if(arr[i] >= 2*med)
            count++;
        que.erase(lower_bound(que.begin(), que.end(), arr[i-d]));
        que.insert(upper_bound(que.begin(), que.end(), arr[i]), arr[i]);
    }

    cout << count;

    return 0;
}
