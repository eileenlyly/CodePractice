/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        if(p != nullptr) s.push(p);
        while(!s.empty()){
            p = s.top();
            s.pop();
            res.push_back(p -> val);
            if(p -> right != nullptr) s.push(p -> right);
            if(p -> left != nullptr) s.push(p -> left);
        }
        return res;
    }
};