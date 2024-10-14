#include <string>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "# "; // Use "#" to represent null
        }
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return contr(iss);
    }

private:
    TreeNode* contr(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(stoi(val));
        newNode->left = contr(iss);
        newNode->right = contr(iss);
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
