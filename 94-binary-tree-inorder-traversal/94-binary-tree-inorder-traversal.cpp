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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> st;
        // st.push(root);
        TreeNode *temp = root;
        vector<int> ans;
        while(1){
            if(temp!=NULL){
                st.push(temp);
                temp = temp->left;
            }else{
                if(st.empty() and temp==NULL) break;
                temp = st.top();
                ans.push_back(temp->val);
                st.pop();
                temp = temp->right;
                
            }
            
        }
        
            
        
        return ans;
        
    }
};