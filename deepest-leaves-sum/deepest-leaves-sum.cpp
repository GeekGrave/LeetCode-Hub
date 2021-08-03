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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL and root->right == NULL){
            return root->val;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(NULL);
        
        int sum = 0,res = 0;
        while(!queue.empty()){
            TreeNode *node = queue.front();
            queue.pop();
            if(node!=NULL){
                sum+=node->val;
                if(node->left != NULL) queue.push(node->left);
                if(node->right!=NULL) queue.push(node->right);
            }else{
                res = sum;
                sum = 0;
                if(!queue.empty()) queue.push(NULL);
            }
        }
        return res;
    }
};