//int overflow!
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        for(int i = 1;i <= numRows; i++){
            vector<int> line;
            for(int j = 1; j <= i; j++){
                line.push_back(pascal(i,j));
            }
            res.push_back(line);
        }
        return res;
    }
    int pascal(int i, int j){
        if(j == 1 || j == i) return 1;
        if(j >= i/2+1) j = i-j+1;
        double val = 1;
        int m = 1;
        for(int k = 1; k < j; k++){
            val = val*(i-k)/(j-k);
        }
        return (int)(val+0.5);
    }
};