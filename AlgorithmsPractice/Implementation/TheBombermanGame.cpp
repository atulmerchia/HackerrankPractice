#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> grid;

grid detonate(grid init, int r, int c){
    grid next (r, vector<char>(c, 'O'));

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(init[i][j] == 'O'){
                next[i][j] = '.';
                if(i) next[i-1][j] = '.';
                if(i < r-1) next[i+1][j] = '.';
                if(j) next[i][j-1] = '.';
                if(j < c-1) next[i][j+1] = '.';
            }

    return next;
}

ostream &operator<<(ostream & os, grid g){
    for(vector<char> row : g){
        for(char c : row)
            os << c;
        os << endl;
    }
    return os;
}

int main(){
    int r, c, n; cin >> r >> c >> n;
    grid initState(r, vector<char>(c));
    for(vector<char> & row : initState)
        for(char & c : row)
            cin >> c;

    grid stateone = detonate(initState, r, c);
    grid statetwo = detonate(stateone, r, c);
    grid allbombs (r, vector<char>(c, 'O'));

    if(n <= 1) cout << initState;
    else if(n % 4 == 1) cout << statetwo;
    else if(n % 2 == 1) cout << stateone;
    else cout << allbombs;
}
