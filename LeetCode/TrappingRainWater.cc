class Solution {
public:
    int trap(int A[], int n) {
        if(n < 3) return 0;
        int sum = 0;
        int left_highest[n];
        left_highest[0] = 0;
        int max = A[0];
        for(int i = 1; i < n; i++){
            left_highest[i] = max;
            if(max < A[i]) max = A[i];
        }
        int right_highest[n];
        right_highest[n-1] = 0;
        max = A[n-1];
        for(int i = n-2; i >= 0; i--){
            right_highest[i] = max;
            if(max < A[i]) max = A[i];
        }
        for(int i = 0; i < n; i++){
            int height = min(left_highest[i], right_highest[i]);
            if(height <= A[i]) continue;
            else sum += height - A[i];
        }
        return sum;
    }
};