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
    int maxPathDown(TreeNode *root, int &maxi){
        if(!root){
            return 0;
        }
        // either we chose to go down or we dont 
        // 0 if we dont 
        // maxPathDown(left, max) if yes
        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));

        // either we do actually take that u shape or we dont because we already found something better 
        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;

    }
};
