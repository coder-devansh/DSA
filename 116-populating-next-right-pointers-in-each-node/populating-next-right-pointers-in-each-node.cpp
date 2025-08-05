/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(root==NULL){
            return root;
        }
        while(!q.empty()){
            int size=q.size();
            Node*prev=NULL;
           
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                if(prev==NULL){
                    prev=it;
                }else{
                    prev->next=it;
                    prev=it;
                }
                if(i==size-1 && prev!=NULL){
                    prev->next=it;
                    it->next=NULL;

                }
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
        }
        return root;
        
    }
};