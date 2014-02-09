class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int first = A[0];
        int second = A[1];
        int B[n];
        std::fill(B, B+n, -1);
        int cur = 0;
        for(int i = 2; i < n; i++){
            if(A[i] == first){
                B[cur++] = i;
            }
            first = second;
            second = A[i];
        }
        int move = 0;
        cur = 0;
        for(int i = 0; i < n-move; i++){
            if(i+move == B[cur]){
                move++;
                cur++;
                i--;
            }
            else A[i] = A[i+move];
        }
        return n - move;
    }
};