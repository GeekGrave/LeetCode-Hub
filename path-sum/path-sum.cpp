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
    int t;
    bool dfs(TreeNode * root, int s){
        if(root==NULL) return false;
        s+=root->val;
        int ans=false;
        if(root->left ==NULL and root->right == NULL){
            if(s==t){
                return true;
            }
            else return false;
        }else{
            ans |= dfs(root->left,s) | dfs(root->right,s);
        }
        return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        return dfs(root,0);
    }
};