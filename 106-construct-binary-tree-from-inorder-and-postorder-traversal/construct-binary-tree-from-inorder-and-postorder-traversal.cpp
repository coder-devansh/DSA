#include <vector>
using namespace std;

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
    TreeNode* construct(vector<int>& preorder, int prestart, int preend, 
                        vector<int>& inorder, int instart, int inend) {
        if (prestart > preend || instart > inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inrootIndex = instart; // Index of the root in inorder array
        while (inorder[inrootIndex] != root->val) {
            inrootIndex++;
        }
        
        int numsLeft = inrootIndex - instart; // Number of nodes in left subtree

        root->right = construct(preorder, prestart + 1, prestart + numsLeft, 
                                inorder, instart, inrootIndex - 1);
        root->left = construct(preorder, prestart + numsLeft + 1, preend, 
                                 inorder, inrootIndex + 1, inend);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        reverse(preorder.begin(),preorder.end());
        reverse(inorder.begin(),inorder.end());

        return construct(preorder, 0, preorder.size() - 1, 
                         inorder, 0, inorder.size() - 1);
    }
};
