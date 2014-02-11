class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        int val = root -> val;
        if(val == sum && !root -> left && !root -> right){
            vector<int> tmp;
            tmp.push_back(val);
            res.push_back(tmp);
            return res;
        }
        if(root -> left){
            vector<vector<int>> prev_left = pathSum(root -> left, sum - val);
            for(int i = 0; i < prev_left.size(); i++){
                prev_left[i].insert(prev_left[i].begin(),val);
                res.push_back(prev_left[i]);
            }
        }
        if(root -> right){
            vector<vector<int>> prev_right = pathSum(root -> right, sum - val);
            for(int i = 0; i < prev_right.size(); i++){
                prev_right[i].insert(prev_right[i].begin(),val);
                res.push_back(prev_right[i]);
            }
        }
        return res;
    }
};