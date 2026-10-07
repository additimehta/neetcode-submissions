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

private: 
    vector<vector<int>> traversal;
    int level = 0;

public:

    void dfs(TreeNode *root, int level){
        if(!root){
            return;
        }

        if(traversal.size() == level){
            traversal.push_back({});
        }
        traversal[level].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // for each level we go down in we add it to a new array
        if(!root){
            {}; // we dont include in our traversal list
        }

        dfs(root, level);

        return traversal;
        
    }
};
