class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 1) return A[0];
        int sum = A[0];
        int res = A[0];
        for(int i = 1; i < n; i++){
            sum = A[i]>sum+A[i] ? A[i]:sum+A[i];
            res = res>sum ? res:sum;
        }
        return res;
    }
};