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
    int T;
    void dfs(TreeNode *curr, vector<vector<int> > &v,vector<int> temp,int s){
        if(curr->left == NULL and curr->right ==NULL){
            s+=curr->val;
            temp.push_back(curr->val);
            if(s==T){
                v.push_back(temp);
            }
            return;
        }
        temp.push_back(curr->val);
        s+=curr->val;
        if(curr->left!=NULL){
            dfs(curr->left,v,temp,s);
        }
        if(curr->right!=NULL){
            dfs(curr->right,v,temp,s);
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        T = targetSum;
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        dfs(root,ans,{},0);
        return ans;
    }
};