#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> matrix (h, vector<int>(w, 0));

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> matrix[i][j];

    int res = 2 * h * w;

    for(int i = 0; i < h; i++){
        res += matrix[i][0];
        for(int j = 1; j < w; j++)
            res += abs(matrix[i][j] - matrix[i][j-1]);
        res += matrix[i][w-1];
    }

    for(int i = 0; i < w; i++){
        res += matrix[0][i];
        for(int j = 1; j < h; j++)
            res += abs(matrix[j][i] - matrix[j-1][i]);
        res += matrix[h-1][i];
    }

    cout << res;

    return 0;
}
