#include <bits/stdc++.h>

using namespace std;

struct node{
    int level = 0, left = -1, right = -1;
};

void traverse(node tree [], int index = 1){
    if(tree[index].left > 0) traverse(tree, tree[index].left);
    cout << index << " ";
    if(tree[index].right > 0) traverse(tree, tree[index].right);
}

int main(){
    int n; cin >> n;
    node tree [n+1];
    tree[1].level = 1;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        if(l != -1)
            tree[l].level = tree[i].level + 1;
        if(r != -1)
            tree[r].level = tree[i].level + 1;
        tree[i].left = l;
        tree[i].right = r;
    }

    int t; cin >> t;
    while(t--){
        int level; cin >> level;
        for(node & n : tree){
            if(n.level % level == 0){
                swap(n.left, n.right);
            }
        }

        traverse(tree);
        cout << endl;
    }

    return 0;
}
