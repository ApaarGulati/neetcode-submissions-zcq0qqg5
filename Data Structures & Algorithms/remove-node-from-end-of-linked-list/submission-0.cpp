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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_node=new ListNode();
        dummy_node->next=head;
        ListNode* previous=dummy_node;
        ListNode* current=head;
        ListNode* front=head;
        for(int i=0;i<n-1;i++){
            front=front->next;
        }
        while(front->next!=nullptr){
            front=front->next;
            current=current->next;
            previous=previous->next;
        }
        previous->next=current->next;
        return dummy_node->next;
    }
};
