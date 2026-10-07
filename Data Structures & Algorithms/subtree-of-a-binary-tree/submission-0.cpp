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

    bool sameTree(TreeNode *tree1, TreeNode *tree2){
        if(!tree1 && !tree2){
            return true;
        }else if(!tree1 && tree2 || tree1 && !tree2){
            return false;
        }

        if(tree1->val != tree2->val){
            return false;
        }else {
            return (sameTree(tree1->left, tree2->left) && sameTree(tree1->right, tree2->right));
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // maybe check if the node root is the same 
        // then recursively check left and right if they are the same


        /// what we want to check is if the subroot and root are the same tree
        // at some instance

        if(!root && !subRoot){
            return true;
        }else if(!root && subRoot || root && !subRoot){
            return false;
        }

        if(root->val == subRoot->val){
            bool output = sameTree(root, subRoot);
            if(output){
                return true;
            }
        }

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));

        
    }
};
