class Node{
public:
    Node* next;
    Node* prev;
    int val;
    int ky;
    Node(){
        this->next=nullptr;
        this->prev=nullptr;
        this->val=0;
        this->ky=0;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> ptrs;
    Node* head;
    Node* tail;
    int cur_size;
    int max_size;
    LRUCache(int capacity) {
        this->max_size=capacity;
        this->head=nullptr;
        this->tail=nullptr;
        this->cur_size=0;
    }
    
    int get(int key) {
        if(ptrs.find(key)!=ptrs.end()){
            if(cur_size>1){
                Node* cur=ptrs[key];
                // cout<<"curval"<<cur->val<<endl;
                if(cur!=tail){
                    if(cur==head){
                        head=head->next;
                    }
                    if(cur->prev!=nullptr){
                        cur->prev->next=cur->next;
                        // cout<<"changed prev's nxt";
                    }
                    if(cur->next!=nullptr){
                        cur->next->prev=cur->prev;
                        // cout<<"changed next's prv";
                    }
                    tail->next=cur;
                    cur->prev=tail;
                    cur->next=nullptr;
                    tail=cur;
                }
            }
            // cout<<"crsz: "<<cur_size<<endl;
            // cout<<"get1: ";
            // Node* curnd=head;
            // while(curnd!=nullptr){
            //     cout<<curnd->ky<<","<<curnd->val<<"==>";
            //     curnd=curnd->next;
            // }
            // cout<<endl;
            // cout<<endl;
            return ptrs[key]->val;
        }
        // cout<<"crsz: "<<cur_size<<endl;
        // cout<<"get2: ";
        // Node* curnd=head;
        // while(curnd!=nullptr){
        //     cout<<curnd->ky<<","<<curnd->val<<"==>";
        //     curnd=curnd->next;
        // }
        // cout<<endl;
        // cout<<endl;
        return -1;
    }
    
    void put(int key, int value) {
        if(ptrs.find(key)!=ptrs.end()){
            ptrs[key]->val=value;
            // cout<<"tail: ";
            // if(tail==nullptr){
            //     cout<<"nl\n";
            // }
            // else{
            //     cout<<tail->ky<<","<<tail->val<<endl;
            // }
            get(key);
        }
        else{
            if(cur_size==0){
                head=new Node();
                tail=head;
                head->next=nullptr;
                head->prev=nullptr;
                tail->prev=nullptr;
                tail->next=nullptr;
                head->val=value;
                head->ky=key;
                ptrs[key]=head;
                cur_size++;
            }
            else{
                tail->next=new Node();
                tail->next->prev=tail;
                tail=tail->next;
                tail->val=value;
                tail->ky=key;
                ptrs[key]=tail;
                cur_size++;
            }
            if(cur_size>max_size){
                cur_size--;
                int key=head->ky;
                if(ptrs.find(key)!=ptrs.end()){
                    ptrs.erase(key);
                }
                head=head->next;
                head->prev=nullptr;
            }
        }
        // cout<<"crsz: "<<cur_size<<endl;
        // cout<<"put1: ";
        // Node* curnd=head;
        // while(curnd!=nullptr){
        //     cout<<curnd->ky<<","<<curnd->val<<"==>";
        //     curnd=curnd->next;
        // }
        // cout<<endl;
        // if(tail!=nullptr){
        //     cout<<"tail: "<<tail->ky<<","<<tail->val<<endl;
        // }
        // else{
        //     cout<<"tail: nulptr\n";
        // }
        // cout<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */