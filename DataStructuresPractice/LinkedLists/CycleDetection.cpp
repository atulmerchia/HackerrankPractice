bool has_cycle(SinglyLinkedListNode* head) {
    bool res = false;
    vector<SinglyLinkedListNode*> truePath;
    auto node = head;
    while(node != nullptr){
        if(node->next == node){
            res = true;
            break;
        }
        truePath.push_back(node);
        auto temp = node;
        node = node->next;
        temp->next = temp;
    }
    for(int i = 1; i < truePath.size(); i++)
        truePath[i-1]->next = truePath[i];
    truePath.back()->next = nullptr;
    return res;
}
