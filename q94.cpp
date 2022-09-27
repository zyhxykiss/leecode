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
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        my_inorderTraversal(root);
        return nodes;
        
    }
private:
    vector<int> nodes;
    void my_inorderTraversal(TreeNode* root){
        if (root == NULL) return;
        my_inorderTraversal(root -> left);
        nodes.push_back(root->val);
        my_inorderTraversal(root -> right);
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * current = root;
        stack<TreeNode*> st;
        auto p = root;
        vector<int> res;

        while(p){
            st.push(p);
            p = p -> left;
        }

        while (!st.empty()){
            auto node = st.top();
            st.pop();
            res.push_back(node -> val);
            p = node -> right;
            while (p)
            {
                st.push(p);
                p = p -> left; 
            }
        }
        return res;
    }
};
