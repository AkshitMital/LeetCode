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
class FindElements {
private:
    unordered_set<int> st;
    void recoverTree(TreeNode* temp) {
        if(temp == NULL) return;
        
        if(temp->left) {
            temp->left->val = 2 * temp->val + 1;
            st.insert(temp->left->val);
            recoverTree(temp->left);
        }

        if(temp->right) {
            temp->right->val = 2 * temp->val + 2;
            st.insert(temp->right->val);
            recoverTree(temp->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        st.insert(0);
        recoverTree(root);
    }
    
    bool find(int target) {
        return (st.find(target) != st.end()) ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */