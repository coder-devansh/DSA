class Node{
    public:
    int key;
    int val;
    Node*prev;
    Node*next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
    }

};

class LRUCache {
public:
int size;
map<int,Node*>mp;
Node*head=new Node(-1,-1);
Node*tail=new Node(-1,-1);
void appendAthead(Node*node){
    Node*temp=head->next;
    node->prev=head;
    head->next=node;
    node->next=temp;
    temp->prev=node;

   
   


}
void remove(Node*node){
    Node*delprev=node->prev;
    Node*delnext=node->next;
    delnext->prev=delprev;
    delprev->next=delnext;
    
    
}

    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
       
        size=capacity;

        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node*ptr=mp[key];
            int val=ptr->val;
            remove(ptr);
            appendAthead(new Node(key,val));
            mp[key]=head->next;
            return val;
        }
        return -1;

        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*ptr=mp[key];
            mp.erase(key);
            remove(ptr);
        }
        if(mp.size()==size){
            mp.erase(tail->prev->key);
            remove(tail->prev);
            
        }
        appendAthead(new Node(key,value));
        mp[key]=head->next;
        
        

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */