bool checkBST(Node* root) {
		Node *left = root->left, *right = root->right;
        if(left){
            if(left->data >= root->data) return false;
            auto edge = left;
            while(edge->right)
                edge = edge->right;
            if(edge->data >= root->data) return false;
        }
        if(right){
            if(right->data <= root->data) return false;
            auto edge = right;
            while(edge->left)
                edge = edge->left;
            if(edge->data <= root->data) return false;
        }
        if(left && right)
            return checkBST(left) && checkBST(right);
        if(left)
            return checkBST(right);
        if(right)
            return checkBST(left);
        return true;
	}
