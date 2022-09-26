class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s)
        res = 0
        
        for i in range(length):
            for j in range(i, length):
                if self.check(i, j, s):
                    res  = max(res, j-i+1)
        
        return res
    
    def check(self, start, end, s):
        chars = set()

        for i in range(start, end+1):
            c = s[i]
            if c in chars:
                return False
            chars.add(c)
        
        return True
