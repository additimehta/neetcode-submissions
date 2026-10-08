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
    int count = 0;

public:

    int dfs(TreeNode *root, int maxNum){
        if(!root){
            return 0;
        }

        int res = 0;
        if(root->val >= maxNum){
            res = 1;
        }

        maxNum = max(maxNum, root->val);
        res+= dfs(root->left, maxNum);
        res+= dfs(root->right, maxNum);
        return res;


    }
    int goodNodes(TreeNode* root) {

        // good node x is a path froom to node x which conntains no value greater than x
        // the root will always be a good ndode
        // check left and right and see if left || right > root
        // if yes add that too the count
        // keep going down and keep the largest num u seen
        // if the current number is >= to that number then we are good
        return dfs(root, root->val);
    }
};
