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

class Codec {

private:
public:
    void preorder(TreeNode *root, string &res){
        if(!root){
            res += "#,";
            return;
        }

        res += to_string(root->val) + ",";
        preorder(root->left, res);
        preorder(root->right, res);

    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // instead of serliazing with a inorer preodder
        //just do preorder
        // preorder is like ROOT LEFT RIGHT
        // keep in mind if we run into null thne put #
        string res = "";
        preorder(root, res);
        cout << res << endl;
        return res;

        
    }

    TreeNode *buildTree(vector<string> &nodes, int &preIdx){
        if(nodes[preIdx] == "#"){
            preIdx++;
            return nullptr;
        }

        int rootVal = stoi(nodes[preIdx]);

        TreeNode *root = new TreeNode(rootVal);
        preIdx++;
        root->left = buildTree(nodes, preIdx);
        root->right = buildTree(nodes, preIdx);
        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        // the idea is that 

       stringstream ss(data);
       string token;
       vector<string> nodes;
       while(getline(ss, token, ',')){
        cout << token << endl;
        nodes.push_back(token);
       }
       int preIdx = 0;

       return buildTree(nodes, preIdx);
    }
};
