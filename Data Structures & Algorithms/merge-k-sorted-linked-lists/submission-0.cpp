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
        while(true){
            int mi=1e5+5;
            for(auto&ptr:lists){
                if(ptr!=nullptr){
                    mi=min(mi,ptr->val);
                }
            }
            if(mi==1e5+5){
                break;
            }
            else{
                for(auto&ptr:lists){
                    if(ptr!=nullptr && ptr->val==mi){
                        if(cur==nullptr){
                            cur=ptr;
                            head=ptr;
                        }
                        else{
                            cur->next=ptr;
                            cur=cur->next;
                        }
                        ptr=ptr->next;
                        break;
                    }
                }
            }
        }
        return head;
    }
};