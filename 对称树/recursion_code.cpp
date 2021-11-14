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
    int start_num = 0;
    int end_num = 0;
    TreeNode* level[1000];
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        else {
            level[1] = root;
            return isLevelSym(root->left, root->right);
        }
            
    }
    
    bool isLevelSym(TreeNode *left, TreeNode *right) {
        if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right != nullptr) {
            if (left->val == right->val) {
                return isLevelSym(left->left, right->right) && isLevelSym(left->right, right->left);
            }else {
                return false;
            }
        }
        return true;
    }
};
