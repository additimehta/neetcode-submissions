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
    vector<vector<int>> levelTraversal;
    int level = 0;
public:

    void traverse(TreeNode *root, int level){
        if(!root){
            return;
        }


        if(level == levelTraversal.size() ){
            levelTraversal.push_back({});
        }

    
        levelTraversal[level].push_back(root->val);
        traverse(root->right, level+1);
        traverse(root->left, level+1);

    }

    vector<int> rightSideView(TreeNode* root) {

        // if a branch's left and right exist
        // on the right side will be exposed

        // the root is always exposed 
        // for the right side we need to go and check how far right is exposed
        
        // because depending on how far right is exposed
        // left side will only be expposed iff the length of the tree is larger than right side
        if(!root){
            return {};
        }

        traverse(root, level);

         for(int i = 0; i < levelTraversal.size(); i++){
            for(int j = 0; j < levelTraversal[i].size(); j++){
                cout << "Level " << i <<  " " << levelTraversal[i][j] << endl;
            }
         }

        vector<int> sol;


        for(int i = 0; i < levelTraversal.size(); i++){
            int last = levelTraversal[i].front();
            sol.push_back(last);
        }

        return sol;
        
    }
};
