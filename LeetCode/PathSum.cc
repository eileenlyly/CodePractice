class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        vector<int> allSum = SumPaths(root);
        if(std::find(allSum.begin(), allSum.end(), sum) != allSum.end()) return true;
        return false;
    }
    vector<int> SumPaths(TreeNode *root){
        vector<int> res;
        if(!root) return res;
        int val = root -> val;
        if(!root -> left && !root -> right){
            res.push_back(val);
            return res;
        }
        vector<int> left = SumPaths(root -> left);
        vector<int> right = SumPaths(root -> right);
        for(int i = 0; i < left.size(); i++){
            res.push_back(left[i] + val);
        }
        for(int i = 0; i < right.size(); i++){
            res.push_back(right[i] + val);
        }
        return res;
    }
};