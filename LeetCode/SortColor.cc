class Solution {
public:
    void sortColors(int A[], int n) {
        int red_index = 0;
        int blue_index = n - 1;
        for(int i = 0; i <= blue_index; i++){
            if(A[i] == 0) std::swap(A[i], A[red_index++]);
            if(A[i] == 2) std::swap(A[i--], A[blue_index--]);
        }
        return;
    }
};