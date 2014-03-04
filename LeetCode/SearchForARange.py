class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        def _searchRange(pre, A):
            if len(A) == 0:
                return [-1,-1]
            mid = len(A)/2
            if A[mid] > target:
                return _searchRange(pre, A[0:mid])
            elif A[mid] < target:
                return _searchRange(pre+mid+1, A[mid+1:])
            else:
                i = mid - 1
                j = mid + 1
                while i > -1 and A[i] == target:
                    i -= 1
                while j < len(A) and A[j] == target:
                    j += 1
                return [pre+i+1,pre+j-1]
            
        return _searchRange(0, A)
            