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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* prev=new ListNode();
        prev->next=head;
        ListNode* cur=head;
        int carry=0;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        while(ptr1!=nullptr && ptr2!=nullptr){
            int ans=carry+ptr1->val+ptr2->val;
            cur->val=ans%10;
            carry=ans/10;
            cur->next=new ListNode();
            cur=cur->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            prev=prev->next;
        }
        while(ptr1!=nullptr){
            int ans=carry+ptr1->val;
            cur->val=ans%10;
            carry=ans/10;
            cur->next=new ListNode();
            cur=cur->next;
            ptr1=ptr1->next;
            prev=prev->next;
        }
        while(ptr2!=nullptr){
            int ans=carry+ptr2->val;
            cur->val=ans%10;
            carry=ans/10;
            cur->next=new ListNode();
            cur=cur->next;
            ptr2=ptr2->next;
            prev=prev->next;
        }
        if(carry){
            cur->val=carry;
        }
        if(cur->val==0){
            prev->next=nullptr;
        }

        return head;
        
    }
};