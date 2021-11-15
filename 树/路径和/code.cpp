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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (root == nullptr)
            return false;
        return got(root, root, targetSum, 0);
        
    }
    
    bool got(TreeNode* parent, TreeNode* root, int targetSum, int currentSum) {
        if (root == nullptr && targetSum  == currentSum) {
            if (parent->left == nullptr && parent->right == nullptr)
                return true;
            else
                return false;
        }
        else if (root != nullptr)
            return got(root, root->left, targetSum, currentSum + root->val)
                || got(root, root->right, targetSum, currentSum + root->val);
        else
            return false;

    }
    
};
