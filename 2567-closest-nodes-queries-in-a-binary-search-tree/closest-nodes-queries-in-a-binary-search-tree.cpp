#include <vector>
#include <limits.h> // For INT_MIN and INT_MAX
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
    vector<int> in; // To store inorder traversal
    vector<vector<int>> ans; // To store results

    // Inorder traversal function
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }

    // Function to find closest nodes using binary search
    void findClosest(int value, const vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MIN; // Closest smaller or equal value
        int maxi = INT_MAX; // Closest larger value

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == value) {
                mini = nums[mid];
                maxi = nums[mid];
                break;
            }
            if (nums[mid] < value) {
                mini = nums[mid]; // Update mini
                low = mid + 1;
            } else {
                maxi = nums[mid]; // Update maxi
                high = mid - 1;
            }
        }

        // If no smaller value found, set mini to -1
        if (mini == INT_MIN) mini = -1;
        // If no larger value found, set maxi to -1
        if (maxi == INT_MAX) maxi = -1;

        ans.push_back({mini, maxi});
    }

    // Main function to process queries
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root); // Perform inorder traversal to get sorted values

        for (int query : queries) {
            findClosest(query, in); // Find closest nodes for each query
        }
        return ans; // Return results
    }
};
