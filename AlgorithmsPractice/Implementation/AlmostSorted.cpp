#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int & i : arr) cin >> i;

    vector<int> copy = arr;
    sort(copy.begin(), copy.end());

    vector<int> outOfPlace;
    for(int i = 0; i < arr.size(); i++)
        if(arr[i] != copy[i])
            outOfPlace.push_back(i+1);

    if(outOfPlace.empty())
        cout << "yes";
    else if(outOfPlace.size() == 2)
        cout << "yes\nswap " << outOfPlace[0] << " " << outOfPlace[1];
    else{
        bool valid = true;
        for(int i = outOfPlace[0]; i < outOfPlace.back(); i++)
            if(arr[i] > arr[i-1])
                valid = false;
        if(valid)
            cout << "yes\nreverse " << outOfPlace[0] << " " << outOfPlace.back();
        else
            cout << "no";
    }

    return 0;
}
