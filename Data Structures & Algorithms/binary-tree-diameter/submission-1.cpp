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
    int height(TreeNode *root){
        if(!root){
            return 0;
        }

        return max(1 + height(root->left), 1+ height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {

        // diameter is the far right


        // total = leftHeight + rightHeight

        if(!root){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameter =  leftHeight + rightHeight;
        int bestDiameter = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(diameter, bestDiameter);

    }
};
