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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        ListNode* cur=head;
        
        set<pair<int,ListNode*>> s;
        for(auto&ptr:lists){
            if(ptr!=nullptr){
                s.insert({ptr->val,ptr});
            }
        }
        while(!s.empty()){
            pair<int,ListNode*> top=*s.begin();
            s.erase(s.begin());
            if(head==nullptr){
                head=top.second;
                cur=top.second;
            }
            else{
                cur->next=top.second;
                cur=cur->next;
            }
            ListNode* nxt=(top.second)->next;
            if(nxt!=nullptr){
                s.insert({nxt->val,nxt});
            }
        }
        return head;
    }
};