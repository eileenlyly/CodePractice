class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(!root) return 0;
        vector<vector<int>> paths = getPath(root);
        return sumPaths(paths);
    }
    vector<vector<int>> getPath(TreeNode *root){
        vector<vector<int>> res;
        if(!root) return res;
        if(!root -> left && !root -> right){
            vector<int> tmp;
            tmp.push_back(root -> val);
            res.push_back(tmp);
            return res;
        }
        vector<vector<int>> left = getPath(root -> left);
        vector<vector<int>> right = getPath(root -> right);
        for(int i = 0; i < left.size(); i++){
            left[i].push_back(root -> val);
            res.push_back(left[i]);
        }
        for(int i = 0; i < right.size(); i++){
            right[i].push_back(root -> val);
            res.push_back(right[i]);
        }
        return res;
    }
    int sumPaths(vector<vector<int>> paths){
        int res = 0;
        for(int i = 0; i < paths.size(); i++){
            for(int j = 0, k = 1; j < paths[i].size(); j++, k *= 10){
                res += paths[i][j]*k;
            }
        }
        return res;
    }
};