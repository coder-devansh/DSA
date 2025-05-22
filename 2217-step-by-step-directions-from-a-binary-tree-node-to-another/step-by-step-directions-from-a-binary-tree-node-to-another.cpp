/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
string temp;
TreeNode*LCA(TreeNode*&root,int start,int dest){
    if(root==NULL){
        return root;
    }
    if(root->val==start || root->val==dest){
        return root;
    }
    auto left=LCA(root->left,start,dest);
    auto right=LCA(root->right,start,dest);
   if(left!=NULL && right!=NULL){
    return root;
   }if(left!=NULL){
    return left;
   }return right;
}
bool find(TreeNode*&root,int dest,string &path,string& current){
    if(root==NULL){
        return false;
    }
    if(root->val==dest){
        if(path.size()==0 || path.size()>current.size()){
           path=current;
        }
        return true;
        
    }
    
    

    current.push_back('L');
        if (find(root->left, dest, path, current)) return true;
        current.pop_back();

        current.push_back('R');
        if (find(root->right, dest, path, current)) return true;
        current.pop_back();
  
return false;

}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string result="";
        
        root=LCA(root,startValue,destValue);
        string path;
        string dest;

        string current1;
        string current2;
        find(root,startValue,path,current1);
        for(int i=0;i<path.size();i++){
            result+='U';
        }
        find(root,destValue,dest,current2);

        result+=dest;
        return result;

        
    }
};