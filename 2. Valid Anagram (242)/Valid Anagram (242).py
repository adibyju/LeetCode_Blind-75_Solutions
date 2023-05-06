class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a=[0]*26
        if len(s)!=len(t):
            return False
        for x in range(0, len(s)):
            a[ord(s[x])-ord('a')]+=1
            a[ord(t[x])-ord('a')]-=1
        for x in range(0,26):
            if a[x]!=0:
                return False
        return True