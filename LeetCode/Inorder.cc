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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p = root;
        stack<TreeNode*> s;
        while(!s.empty() || p != nullptr){
            if(p == nullptr){
                p = s.top();
                s.pop();
                res.push_back(p -> val);
                p = p -> right;
            }
            else{
                s.push(p);
                p = p -> left;
            }
        }
        return res;
    }
};