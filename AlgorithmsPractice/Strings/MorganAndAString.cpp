#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b, int i, int j){
    while(i < a.length() && j < b.length()){
        if(a[i] < b[j]) return true;
        else if(a[i] > b[j]) return false;
        i++;
        j++;
    }

    return i != a.length();
}

int main(){
    int t; cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int aLen = a.length(), bLen = b.length(), i = 0, j = 0;

        while(i < aLen && j < bLen){
            if(a[i] < b[j])
                cout << a[i++];
            else if(a[i] > b[j])
                cout << b[j++];
            else{
                if(compare(a, b, i + 1, j + 1))
                    do{
                        cout << a[i++];
                    }while(i < aLen && a[i] == a[i-1]);
                else
                    do{
                        cout << b[j++];
                    }while(j < bLen && b[j] == b[j-1]);
            }
        }

        while(i < aLen)
            cout << a[i++];
        while(j < bLen)
            cout << b[j++];
        cout << endl;
    }
    return 0;
}
