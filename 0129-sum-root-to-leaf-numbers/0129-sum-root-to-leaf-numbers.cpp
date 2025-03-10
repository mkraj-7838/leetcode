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
    void traverse(TreeNode *root,int &ans,int val){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            ans+=(val*10)+root->val;
            return;
        }
        val=(val*10)+root->val;
        traverse(root->left,ans,val);
        traverse(root->right,ans,val);
    }
    int sumNumbers(TreeNode* root) {
         int ans=0;
         traverse(root,ans,0);
         return ans;
    }
};