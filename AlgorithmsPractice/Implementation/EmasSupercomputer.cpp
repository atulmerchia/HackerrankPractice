#include <bits/stdc++.h>
#include <queue>

using namespace std;

int r, c;
int search(vector<string> grid, int prod, int level){
    if(level == 2)
        return prod;
    int res = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(grid[i][j] == 'G'){
                vector<string> copy = grid;
                copy[i][j] = 'B';
                res = max(res, search(copy, 1, level + 1));
                int len = 1;
                while(len <= i && grid[i-len][j] == 'G'
                      && i+len < r && grid[i+len][j] == 'G'
                      && len <= j && grid[i][j-len] == 'G'
                      && j+len < c && grid[i][j+len] == 'G'){
                    copy[i-len][j] = 'B';
                    copy[i+len][j] = 'B';
                    copy[i][j-len] = 'B';
                    copy[i][j+len] = 'B';
                    res = max(res, search(copy, prod * (4*len+1), level + 1));
                    len++;
                }
            }
    return res;
}


int main(){
    cin >> r >> c;
    vector<string> grid(r);
    for(string & s : grid) cin >> s;

    cout << search(grid, 1, 0);

    return 0;
}
