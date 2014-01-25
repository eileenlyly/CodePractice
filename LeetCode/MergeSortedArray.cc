class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m){
                if(B[i] < A[j]){
                    insert(&A[j], B[i], m - j);
                    m++;
                    break;
                }
                else j++;
            }
            if(j++ == m) insert(A + m++, B[i], 0);
        }
        return;
    }
    void insert(int *a, int b, int n){
            if(n == 0){
                a[0] = b;
                return;
            }
            int tmp1;
            int tmp2;
            tmp1 = a[0];
            a[0] = b;
            for(int i = 0; i < n -1; i++){
                tmp2 = a[i+1];
                a[i+1] = tmp1;
                tmp1 = tmp2;
            }
            a[n] = tmp1;
            return;
        }
};