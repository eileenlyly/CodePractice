class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        def findTarget(A,B,m,n,k):
            if len(A)-m > len(B)-n:
                return findTarget(B,A,n,m,k)
            if len(A) <= m:
                return B[n+k]
            if len(B) <= n:
                return A[m+k]
            if k == 0:
                return min(A[m],B[n])
            ia = min(len(A)-1, k/2+m)
            ib = n+k-(ia-m+1)
            if A[ia] < B[ib]:
                return findTarget(A,B,ia+1,n,k-ia+m-1)
            elif A[ia] > B[ib]:
                return findTarget(A,B,m,ib+1,k-ib+n-1)
            elif A[ia] == B[ib]:
                return A[ia]
            
        m = len(A)
        n = len(B)
        if (m+n) % 2 == 0:
            return (findTarget(A,B,0,0,(m+n)/2-1) + findTarget(A,B,0,0,(m+n)/2))*0.5
        return findTarget(A,B,0,0,(m+n)/2)