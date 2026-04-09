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
    ListNode* reverseList(ListNode* head) {
        // if head is nullptr [sz=0]
        if(head==nullptr){
            return head;
        }
        // if sz=1
        else if(head->next==nullptr){
            return head;
        }
        // if sz=2
        else if(head->next->next==nullptr){
            head->next->next=head;
            head=head->next;
            head->next->next=nullptr;
            return head;
        }
        // if sz>=3
        else{
            // cur
            //            p1   p2
            // []<==>[]<==[]<==[]
            ListNode* p1=head;
            ListNode* p2=head->next;
            while(p2!=nullptr){
                ListNode* p3=p2->next;
                p2->next=p1;
                p1=p2;
                p2=p3;
            }
            head->next=nullptr;
            head=p1;
            return head;
        }
    }
};