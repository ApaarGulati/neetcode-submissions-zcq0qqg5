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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* head=nullptr;
        ListNode* cur=nullptr;
        while(p1!=nullptr && p2!=nullptr){
            if(cur==nullptr){
                if(p1->val < p2->val){
                    head=p1;
                    cur=p1;
                    p1=p1->next;
                }
                else{
                    head=p2;
                    cur=p2;
                    p2=p2->next;
                }
            }
            else{
                if(p1-> val < p2->val){
                    cur->next=p1;
                    p1=p1->next;
                    cur=cur->next;
                }
                else{
                    cur->next=p2;
                    p2=p2->next;
                    cur=cur->next;
                }
            }
        }
        while(p1!=nullptr){
            if(cur==nullptr){
                head=p1;
                cur=p1;
                p1=p1->next;
            }
            else{
                cur->next=p1;
                p1=p1->next;
                cur=cur->next;
            }
        }
        while(p2!=nullptr){
            if(cur==nullptr){
                head=p2;
                cur=p2;
                p2=p2->next;
            }
            else{
                cur->next=p2;
                p2=p2->next;
                cur=cur->next;
            }
        }
        return head;
    }
};