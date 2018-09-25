#include <bits/stdc++.h>

using namespace std;

int main() {

    int r, c, n; cin >> r >> c >> n;
    int arr[r][c];
    int res[r][c];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            int topleft = min(min(i, r-i-1), min(j, c-j-1));

            int lower = r - topleft - 1;
            int right = c - topleft - 1;
            int perim = 2*(lower-topleft + right-topleft);

            int newrow = i, newcol = j;
            for(int a = 0; a < n % perim; a++)
                if(newcol == topleft && newrow < lower) newrow++;
                else if(newrow == lower && newcol < right) newcol++;
                else if(newrow > topleft && newcol == right) newrow--;
                else if(newrow == topleft && newcol > topleft) newcol--;
            res[newrow][newcol] = arr[i][j];
        }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
