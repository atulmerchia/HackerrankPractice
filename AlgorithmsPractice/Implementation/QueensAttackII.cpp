#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    int qrow, qcol; cin >> qrow >> qcol;

    int north = n - qrow,
        east = n - qcol,
        south = qrow - 1,
        west = qcol - 1;
    int northwest = min(north, west),
        northeast = min(north, east),
        southwest = min(south, west),
        southeast = min(south, east);

    while(k--){
        int row, col; cin >> row >> col;
        if(row == qrow)
            col < qcol ? west = min(west, qcol - col - 1) : east = min(east, col - qcol - 1);
        else if(col == qcol)
            row < qrow ? south = min(south, qrow - row - 1) : north = min(north, row - qrow - 1);
        else if(col - qcol == row - qrow)
            row < qrow ? southwest = min(southwest, qrow - row - 1) : northeast = min(northeast, row - qrow - 1);
        else if(col - qcol == qrow - row)
            row < qrow ? southeast = min(southeast, qrow - row - 1) : northwest = min(northwest, row - qrow - 1);
    }

    cout << north + south + east + west + northwest + northeast + southwest + southeast;

    return 0;
}
