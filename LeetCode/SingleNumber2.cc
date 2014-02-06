class Solution {
public:
    int singleNumber(int A[], int n) {
        const int int_len = sizeof(int)*8;
        int count[int_len];
        fill_n(count,int_len,0);
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < int_len; j++){
                count[j] += (A[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        return getValue(count, int_len);
    }
    
    int getValue(int A[], int n){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == 1)
                res += 1 << i;
        }
        return res;
        
    }
};