class Node{
    public:
    int val;
    int key;
    Node*next;
   Node*prev;
   public:
   Node(int key,int val)
   {
    this->val=val;
    this->key=key;
    next=NULL;
    prev=NULL;
   }

};

class LRUCache {
public:
int size;
Node*head=new Node(-1,-1);
Node*tail=new Node(-1,-1);

map<int,Node*>mp;
void InsertNode(Node*node){
    Node*next=head->next;
    head->next=node;
    node->prev=head;
    node->next=next;
    next->prev=node;
}

void deleteNode(Node*node){
    Node*delprev=node->prev;
    Node*delnext=node->next;
    delprev->next=delnext;
    delnext->prev=delprev;
}



    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int val=mp[key]->val;
            deleteNode(mp[key]);
            InsertNode(new Node(key,val));
            mp[key]=head->next;
            return val;
        }
        return -1;


        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            InsertNode(new Node(key,value));
            mp[key]=head->next;
            return;

        }
        if(mp.size()==size){
        Node*node=tail->prev;
        int key1=node->key;
        mp.erase(key1);

            deleteNode(tail->prev);
            InsertNode(new Node(key,value));
            mp[key]=head->next;
            return;
        }
        

        InsertNode(new Node(key,value));
        mp[key]=head->next;
        


        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */