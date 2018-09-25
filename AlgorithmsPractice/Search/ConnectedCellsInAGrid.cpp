#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> matrix;

int getsize(int row, int col){
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    int count = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        row = p.first, col = p.second;

        if(!matrix[row][col]) continue;

        count++;
        matrix[row][col] = 0;

        if(row){
            if(col) q.push(make_pair(row-1, col-1));
            q.push(make_pair(row-1, col));
            if(col != m-1) q.push(make_pair(row-1, col+1));
        }
        if(col) q.push(make_pair(row, col-1));
        if(col != m-1) q.push(make_pair(row, col+1));
        if(row != n-1){
            if(col) q.push(make_pair(row+1, col-1));
            q.push(make_pair(row+1, col));
            if(col != m-1) q.push(make_pair(row+1, col+1));
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;

    matrix.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    int best = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j])
                best = max(best, getsize(i, j));
    cout << best;
    return 0;
}
