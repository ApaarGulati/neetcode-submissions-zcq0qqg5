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
    ListNode* reverse_ll(ListNode* head){
        if(head==nullptr){
            return head;
        }
        else{
            // 3 ==> 4
            ListNode* p1=head;
            ListNode* p2=head->next;
            while(p1!=nullptr && p2!=nullptr){
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

    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* p1=head1;
        ListNode* p2=head2;
        ListNode* newhead=nullptr;
        ListNode* cur=nullptr;
        while(p1!=nullptr && p2!=nullptr){
            if(newhead==nullptr){
                newhead=p1;
                cur=p1;
                p1=p1->next;
                cur->next=p2;
                p2=p2->next;
                cur=cur->next;
            }
            else{
                cur->next=p1;
                p1=p1->next;
                cur=cur->next;

                cur->next=p2;
                p2=p2->next;
                cur=cur->next;
            }
        }
        while(p1!=nullptr){
            if(newhead==nullptr){
                newhead=p1;
                break;
            }
            else{
                cur->next=p1;
                p1=p1->next;
                cur=cur->next;
                break;
            }
        }
        while(p2!=nullptr){
            if(newhead==nullptr){
                newhead=p2;
                break;
            }
            else{
                cur->next=p2;
                p2=p2->next;
                cur=cur->next;
                break;
            }
        }
        return newhead;
    }

    void reorderList(ListNode* head) {
        // find midpt using slow and fast, break just after slow
        // reverse second part
        // merge the 2 together
        //                   s                 f
        // 1 ==> 2 ==> 3 ==> 4 ==> 5 ==> 6 ==> 7
        // _
        // 1
        // 1 ==> 2
        // 1 ==> 2 ==> 3
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=nullptr && slow->next!=nullptr && fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* p1=head;
        ListNode* p2=nullptr;
        if(slow->next!=nullptr){
            p2=slow->next;
            slow->next=nullptr;
        }
        else{
            return;
        }

        // reverse p2 onwards
        p2=reverse_ll(p2);
        ListNode* temp=p2;
        while(temp!=nullptr){
            cout<<(temp->val)<<"==>";
            temp=temp->next;
        }
        cout<<endl;
        head=merge(head,p2);
    }
};