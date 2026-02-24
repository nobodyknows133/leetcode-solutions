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
    int res = 0;
    void dfs(TreeNode* root,int val){
        if(root->left==NULL && root->right==NULL){
            val = val*2+root->val;
            res+=val;
        }
        else{
            val = val*2 + root->val;
            if(root->left!=NULL){
                dfs(root->left,val);
            }
            if(root->right!=NULL){
                dfs(root->right,val);
            }
        }

    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,0);
        return res;
    }
};
