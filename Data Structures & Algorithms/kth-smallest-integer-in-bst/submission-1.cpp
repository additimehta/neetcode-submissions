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
vector<int> nodes;

public:
    void inorder(TreeNode *root){
        if(!root){
            return;
        }else{

            inorder(root->left);
            nodes.push_back(root->val);
            inorder(root->right);

        }

    }
    int kthSmallest(TreeNode* root, int k) {

        // we can also do an inorder traversal
        // the numbers are always sorted in inoreder traversal in BST
        // this wwould save us O(nlogn) and just be O(N)

        inorder(root);
        return nodes[k-1];


        
    }
};
