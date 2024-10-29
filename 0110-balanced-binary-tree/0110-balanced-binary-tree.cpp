/**
 * Definition for a binary tree root.
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
    int findH(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = findH(root->left);
        int rightDepth = findH(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh = findH(root->left);
        int rh = findH(root->right);
        
        if(abs(lh-rh)>1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->left);

        if(!left || !right) return false;
        return true;
    }
};