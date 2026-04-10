/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        vector<ListNode*> v1;
        ListNode* cur=head;
        while(cur!=nullptr){
            v.push_back(cur);
            cur=cur->next;
        }
        int n=v.size();
        int i=0,j=n-1;
        while(i<j){
            v1.push_back(v[i++]);
            v1.push_back(v[j--]);
        }
        if(i==j){
            v1.push_back(v[i++]);
        }
        for(int i=1;i<n;i++){
            v1[i-1]->next=v1[i];
        }
        v1[n-1]->next=nullptr;
    }
};