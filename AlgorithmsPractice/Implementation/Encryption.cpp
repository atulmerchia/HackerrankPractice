#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    string str = "";
    for(char c : s)
        if(c != ' ')
            str += c;
    int rt = sqrt(str.length());
    if(rt * rt != str.length()) rt++;

    for(int i = 0; i < rt; i++){
        for(int j = i; j < str.length(); j += rt)
            cout << str[j];
        cout << " ";
    }

    return 0;
}
