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

    void reversell(ListNode*& head, ListNode*& tail){
        ListNode* dest=tail->next;
        ListNode* cur=head;
        ListNode* nxt=head->next;
        while(cur!=tail){
            cur->next=dest;
            dest=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        cur->next=dest;
        cout<<"tl:----->"<<tail->val;
        cout<<endl;
        cout<<"hd:----->"<<head->val;
        cout<<endl;
        swap(head,tail);
        cout<<"tl:----->"<<tail->val;
        cout<<endl;
        cout<<"hd:----->"<<head->val;
        cout<<endl;
    }

    void printll(ListNode* head){
        ListNode* cur=head;
        while(cur!=nullptr){
            cout<<cur->val<<"==>";
            cur=cur->next;
        }
        cout<<endl;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curhead=head;
        ListNode* curtail=head;
        ListNode* prev=new ListNode();
        prev->next=head;
        if(k==1){
            return head;
        }
        for(int i=0;i<k-1;i++){
            curtail=curtail->next;
        }
        ListNode* save=curtail;
        while(curtail!=nullptr){
            cout<<"ch:"<<curhead->val<<", ct:"<<curtail->val<<endl;
            cout<<"pr:"<<prev->val<<endl;
            reversell(curhead,curtail);
            prev->next=curhead;
            printll(curhead);
            printll(head);
            curhead=curhead->next;
            prev=prev->next;
            curtail=curtail->next;
            for(int i=0;i<k-1;i++){
                if(curtail!=nullptr){
                    curhead=curhead->next;
                    prev=prev->next;
                    curtail=curtail->next;
                }
            }
        }
        return save;
    }
};