class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        def _decode(s):
            if len(s) == 0:
                return 0
            if s[0] == '0':
                return 0
            count = [0] * (len(s)+1)
            count[0] = 1
            count[1] = 1
            for i in range(1,len(s)):
                if s[i] != '0':
                    count[i+1] += count[i]
                if int(s[i-1:i+1]) <= 26 and s[i-1] != '0':
                    count[i+1] += count[i-1]
            return count[-1]
        return _decode(s)