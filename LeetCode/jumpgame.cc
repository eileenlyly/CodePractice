class Solution {
public:
    bool canJump(int A[], int n) {
        int left[n];
        fill_n(left,n,-1);
        left[0] = A[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1],A[i-1])-1;
            if(left[i] < 0) break;
        }
        return left[n-1] >= 0;
    }
};