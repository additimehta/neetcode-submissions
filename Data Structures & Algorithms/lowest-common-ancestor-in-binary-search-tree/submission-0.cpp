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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we can find out where p and q are
        // but how can we store this data?
        // BST when left is < root and right is > root
        // check whether root is p or q
        // if it is p then that is one ancenstor
        // then compare if q or p is
        // depends on where p and q are located
        // like if p and q are just both < than root then their ancensetor cannto be the root node
        // if p || q is the root node then that is one ancenstor 
        // if p and q split up somewhere like then that has to be LCA
        // LCA can generally be found pretty early just find out where do they split up

        // base case is if root is null, we just return null

        if(!root){
            return nullptr;
        }

        if(root == p || root == q){
            return root;
        }
        // the p and q diverge
        if((root->val < p->val && root->val > q->val) || root->val < q->val && root->val > p->val){
            return root;
        }

        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left){
            return left;
        }

        if(right){
            return right;
        }
    }
};
