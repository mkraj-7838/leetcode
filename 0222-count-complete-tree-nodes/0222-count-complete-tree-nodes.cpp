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
    int countNodes(TreeNode* root) {
        stack<TreeNode*>st;
        int count=0;
        if(!root){
            return 0;
        }

        st.push(root);
        while(!st.empty()){
            count++;
            TreeNode* temp=st.top();
            st.pop();
            if(temp && temp->left){
                st.push(temp->left);

            }
            if(temp && temp->right){
                st.push(temp->right);
            }

        }
        return count;
    }
};