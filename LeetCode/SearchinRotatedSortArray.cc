class Solution {
public:
    int search(int A[], int n, int target) {
        return search_array(A, 0, n-1, target); 
    }
    int search_array(int *A, int start, int end, int target){
        if(start == end){
            if(A[start] == target) return start;
            return -1;
        }
        int mid = (end - start - 1)/2 + start;
        if(A[start] > A[end]) return max(search_array(A,start,mid,target), search_array(A,mid+1,end,target));
        if(A[start] < A[end]){
            if(A[start] > target || A[end] < target) return -1;
            return max(search_array(A,start,mid,target), search_array(A,mid+1,end,target));
        } 
    }
};