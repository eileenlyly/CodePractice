class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while(i < n){
            if(A[i] > 0 && A[i] != i+1 && A[i]-1 < n){
                if(A[i] == A[A[i]-1]){
                    i++;
                    continue;
                }
                swap(A[i],A[A[i]-1]);
            }
            else i++;
        }
        for(i = 0; i < n; i++){
            if(A[i] != i+1) return i+1;
        }
        return n+1;
    }
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};