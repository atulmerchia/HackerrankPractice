#include <bits/stdc++.h>
using namespace std;

struct node{
    vector<int> indices;
    node* children[26];
    node* suffix = nullptr;

    node(){
      for(int i = 0; i < 26; i++)
          children[i] = nullptr;
    }
};

node *root;

void insert(string str, int index){
    node* n = root;
    for(char c : str){
        c -= 'a';
        if (n->children[c]==nullptr)
            n->children[c] = new node();
        n = n->children[c];
    }
    n->indices.push_back(index);
}

void bfs(){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* n = q.front();
        q.pop();

        for(int i = 0; i < 26; i++){
            if(n->children[i] != nullptr){
                if(n == root)
                    n->children[i]->suffix = root;
                else{
                    node* s = n->suffix;
                    while(s != nullptr && s->children[i] == nullptr)
                        s = s->suffix;
                    if(s == nullptr)
                        n->children[i]->suffix = root;
                    else
                        n->children[i]->suffix = s->children[i];
                }
                q.push(n->children[i]);
            }
        }
    }
}


vector<vector<int>> query(string s){
    vector<vector<int>> res;

    node* n = root;
    for(char c : s){
        c -= 'a';
        while(n->children[c] == nullptr && n != root)
            n = n->suffix;
        if(n->children[c] == nullptr)
            continue;
        n = n->children[c];
        node* o = n;

        while(o != root){
            if(!o->indices.empty())
                res.push_back(o->indices);
            o = o->suffix;
        }
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);

    int vals[n];
    string str;

    root = new node();

    for(int i = 0; i < n; i++){
        cin >> str;
        insert(str, i);
    }

    for(int i = 0; i < n; i++)
        scanf("%d", &vals[i]);

    bfs();

    int q;
    scanf("%d", &q);

    unsigned long long small = ULLONG_MAX, large = 0;

    for(int i = 0; i < q; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        cin >> str;
        vector<vector<int>> vec = query(str);

        unsigned long long sum = 0;
        for(int i = 0; i < vec.size(); i++)
            for(int j = 0; j < vec[i].size(); j++)
                if(vec[i][j] >= start && vec[i][j] <= end)
                    sum += vals[vec[i][j]];
        if(sum > large) large = sum;
        if(sum < small) small = sum;
    }
    printf("%lld %lld\n", small, large);
    return 0;
}
