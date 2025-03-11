class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        l = 0
        mp = defaultdict(int)
        r = 0
        while r < n:
            mp[s[r]]+=1
            while mp["a"]>=1 and mp["b"]>=1 and mp["c"]>=1:
                res += (n - r)
                mp[s[l]]-=1
                l+=1
            r+=1
        
        return res
