class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        int i = n-1, left = 0, right = m-1;
        for(; i >= 0; i--){
            if(matrix[i][0] <= target) break;
        }
        if(i < 0) return false;
        while(left <= right){
            if(left == right) return target == matrix[i][left];
            int mid = (right - left -1)/2 + left;
            if(matrix[i][mid] > target) right = mid;
            else if (matrix[i][mid] < target) left = mid + 1;
            else return true;
        }
        return false;
    }
};