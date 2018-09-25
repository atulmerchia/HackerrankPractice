#include <bits/stdc++.h>
using namespace std ;

typedef unsigned long long ull;
const int mod = 1e9 + 7;

vector<vector<int>> children;
vector<vector<int>> parent;
vector<int> level;

int height, n;

void dfs(int curr, int prev){
    level[curr] = level[prev] + 1;
    parent[curr][0] = prev;

    for(int c : children[curr])
        if(c != prev)
            dfs(c, curr);
}

void getSparseMatrix(){
    for(int i = 1; i < height; i++)
        for(int j = 1; j <= n; j++)
            if(parent[j][i-1] != -1)
                parent[j][i] = parent[parent[j][i-1]][i-1];
}

int lca(int u, int v){
    if(level[v] < level[u])
        swap(u, v);
    int d = level[u] - level[v];

    for(int i = 0; i < height; i++)
        if((d>>i) & 1)
            v = parent[v][i];

    if(u == v) return u;

    for (int i = height-1; i >= 0; i--)
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}

int main(){
    int q; cin >> n >> q;
    int logn = ceil(log2(n));

    children.resize(n+1);
    parent.resize(n+1, vector<int>(logn));
    level.resize(n+1);

    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }

    level[0] = 0;
    dfs(1, 0);
    getSparseMatrix();

    while(q--){
        ull sum = 0;
        int len; cin >> len;
        int arr [len];
        for(int & i : arr)
            cin >> i;
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                int u = arr[i], v = arr[j], d = lca(u, v);
                sum = (sum + u * v * d) % mod;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
