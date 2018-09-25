#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int evaluate(matrix original, matrix mapTo){
    int sum = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            sum += abs(original[i][j] - mapTo[i][j]);
    return sum;
}

void rotate(matrix & square){
    auto copy = square;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            square[i][j] = copy[2-j][i];
}

matrix getFlipped(matrix square){
    for(int i = 0; i < 3; i++)
        swap(square[i][0], square[i][2]);
    return square;
}

int main(){
    matrix square = {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
    matrix input (3, vector<int>(3));

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> input[i][j];

    int ans = 100000;
    for(int i = 0; i < 4; i++){
        if(i) rotate(square);
        ans = min(ans, evaluate(input, square));
        ans = min(ans, evaluate(input, getFlipped(square)));
    }

    cout << ans;
    return 0;
}
