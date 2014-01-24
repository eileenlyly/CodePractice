class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 2) return n;
        int i = 0;
        for(int j = 1; j < n; j++){
            if(A[j] != A[i]) A[++i] = A[j];
        }
        return i+1;
    }
};