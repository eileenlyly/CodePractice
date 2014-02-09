class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        res = matrix[0];
        matrix.erase(matrix.begin());
        if(--m == 0) return res;
        for(int i = 0; i < m; i++){
            res.push_back(matrix[i][n-1]);
            matrix[i].erase(matrix[i].end()-1);
        }
        if(--n == 0) return res;
        for(int i = n-1; i >= 0; i--){
            res.push_back(matrix[m-1][i]);
        }
        matrix.erase(matrix.end()-1);
        if(--m == 0) return res;
        for(int i = m-1; i >= 0; i--){
            res.push_back(matrix[i][0]);
            matrix[i].erase(matrix[i].begin());
        }
        if(--n == 0) return res;
        vector<int> core = spiralOrder(matrix);
        for(int i = 0; i < core.size(); i++){
            res.push_back(core[i]);
        }
        return res;
    }
};