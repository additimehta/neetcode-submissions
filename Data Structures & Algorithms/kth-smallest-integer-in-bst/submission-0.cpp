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
    void traverse(TreeNode *root){
        if(!root){
            return;
        }else{
            nodes.push_back(root->val);
            traverse(root->right);
            traverse(root->left);
        }

    }
    int kthSmallest(TreeNode* root, int k) {
        // in a bst with only 3 nodes
        // the root is always the 2nd largest, first is left, 3rd is right
        // one way to go around this try to find what the smallest value is that we are looking for
        // for example we can go through the whole bst and put in an array and sort the array and find the kth smallest

        // this amy be costly but still under O(N^2) it will O(nlogn) (cuz of sorting) the bst traversal takes O(N)

        traverse(root);
        sort(nodes.begin(), nodes.end());
        return nodes[k-1];
        
    }
};
