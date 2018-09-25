void decode_huff(node * root, string s) {
    node * n = root;
    for(char c : s){
        if(c == '0')
            n = n->left;
        else
            n = n->right;
        if(n->data){
            cout << n->data;
            n = root;
        }
    }
}
