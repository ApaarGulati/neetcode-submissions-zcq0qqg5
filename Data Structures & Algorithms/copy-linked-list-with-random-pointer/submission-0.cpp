/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> v;
        Node* cur=head;
        while(cur!=nullptr){
            v.push_back(new Node(cur->val));
            cur=cur->next;
        }
        unordered_map<Node*,Node*> newptr;
        cur=head;
        int cnt=0;
        while(cur!=nullptr){
            newptr[cur]=v[cnt];
            cur=cur->next;
            cnt++;
        }
        int n=v.size();
        if(!n){
            return nullptr;
        }
        for(int i=0;i<n-1;i++){
            v[i]->next=v[i+1];
        }
        v[n-1]->next=nullptr;
        cur=head;
        for(int i=0;i<n;i++){
            v[i]->random=newptr[cur->random];
            cur=cur->next;
        }
        return v[0];
    }
};