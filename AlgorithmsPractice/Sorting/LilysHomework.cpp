#include <bits/stdc++.h>

using namespace std;

int evaluate(vector <int> arr, vector<int> mapTo, int n, map <int, int> m) {
    int swaps = 0;
    for(int i = 0; i < n; i++){
        if(mapTo[i] != arr[i]){
           int index = m[mapTo[i]];

           swap(arr[i], arr[index]);

           m[arr[index]] = index;
           swaps++;
        }
    }
    return swaps;
}


int main() {
    int n;
    cin >> n;
    map <int, int> m;

    vector<int> arr(n);
    vector<int> asc(n);
    vector<int> des(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]] = i;
    }

    asc = arr;
    des = arr;

    sort(asc.begin(), asc.end());
    sort(des.begin(), des.end(), greater<int>());

    int result = evaluate(arr, asc, n, m);

    m.clear();
    for(int i = 0; i < n; i++)
        m[arr[i]] = i;
    cout << min(result, evaluate(arr, des, n, m));

    return 0;
}
