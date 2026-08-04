class Node{
    public:
    int key;
    int val;
    Node*prev;
    Node*next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};

int size1;

class LRUCache {
public:
unordered_map<int,Node*>mp;
Node*head=new Node(-1,-1);
Node*tail=new Node(-1,-1);
    LRUCache(int capacity) {
       
        size1=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void InsertAthead(Node*temp){
        Node*next=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=next;
        next->prev=temp;
        mp[temp->key]=temp;

    }
    void deleteFrom(Node*temp){
        Node*start=temp->next;
        Node*end=temp->prev;
        end->next=start;
        start->prev=end;

    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())return -1;
        Node*temp=mp[key];
        deleteFrom(temp);
        InsertAthead(temp);
        
        return temp->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*temp=mp[key];
            temp->val=value;
            deleteFrom(temp);
            InsertAthead(temp);
            return;
        }
         Node*temp=new Node(key,value);
        if(mp.size()==0){
              InsertAthead(temp);
              return;
            

        }
        InsertAthead(temp);
        if(mp.size()>size1){
            mp.erase(tail->prev->key);
            deleteFrom(tail->prev);
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */