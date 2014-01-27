class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        vector<int>::iterator it;
        for(it = digits.end()-1;it >= digits.begin();it--){
            if(c != 0) {
                *it += 1;
                c = *it/10;
                *it %= 10;
            }
        }
        if(c != 0) digits.insert(digits.begin(),1);
        return digits;
    }
};