#include <bits/stdc++.h>

using namespace std;

static string firstTwenty [20] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

int main(){
    int h, m; cin >> h >> m;
    if(m == 0){
        cout << firstTwenty[h - 1] + " o' clock";
        return 0;
    }
    if(m == 30){
        cout << "half past " + firstTwenty[h - 1];
        return 0;
    }

    string join = m < 30 ? " past " : " to ";

    if(m > 30) m = 60 - m;
    else h--;

    if(m == 1) join = " minute" + join;
    else if(m != 15) join = " minutes" + join;

    string min;
    if(m > 20){
        min = firstTwenty[19] + " ";
        m -= 20;
    }
    min += firstTwenty[m - 1];

    cout << min + join + firstTwenty[h%12];

    return 0;
}
