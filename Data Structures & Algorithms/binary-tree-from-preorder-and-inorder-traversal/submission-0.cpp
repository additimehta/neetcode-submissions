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
    int preIdx = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // from inorder we can tell which subtree the node exists
        // first have is always left and next half is right
        // the mid is the root


        // for preorder we can say the the first node is always the root
        // we could go add the root shave off that root from the array
        // then we know from inorder what the left and right are
        // from there we can add the roo


        // inorder [left->root->right]
        // preorder [root->left->right]

        // we can recursively go with the inorder 
        // base case is left inorder is empty dont create new nodes
        // the root will always be the first preorder node
        // find root and then recurse on left and right halves

        if(inorder.empty()){
            return nullptr;
        }

        int rootVal = preorder[preIdx];
        int rootIdx = -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == rootVal){
                rootIdx = i;
                break;
            }
        }


        vector<int>leftArr(inorder.begin(), inorder.begin() + rootIdx);
        vector<int>rightArr(inorder.begin() + rootIdx + 1, inorder.end());

        TreeNode *root = new TreeNode(rootVal);
        preIdx++;
        root->left = buildTree(preorder, leftArr);
        root->right = buildTree(preorder, rightArr);

        return root;
        
    }
};
