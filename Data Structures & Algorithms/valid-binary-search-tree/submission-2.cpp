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
    bool dfs(TreeNode *root, int minVal, int maxVal){
        if(!root){
            return true;
        }

        // is this root even allowed 
        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return dfs(root->left, minVal, root->val) &&
       dfs(root->right, root->val, maxVal);

    }
    bool isValidBST(TreeNode* root) {
        
        // left subtree must be always smaller 
        // right subtree must be always largest

        // so we can dfs by storing maxVal, minVal
        // if on the right subtere we see that the node we encountered is < minVal we continue
        // if not then return false


        // for left side if the node we reach is greater than the maxVal then continue
        // if not return false


        return dfs(root, INT_MIN, INT_MAX);
    }
};
