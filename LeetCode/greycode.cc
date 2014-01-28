class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n < 0) return res;
        if(n == 0){
            res.push_back(0);
            return res;
        }
        else{
            res = grayCode(n-1);
            for(int i = res.size()-1; i >=0; i--){
                int tmp = res[i];
                tmp += 1<<(n-1);
                res.push_back(tmp);
            }
            return res;
        }
        return res;
    }
};