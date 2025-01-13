class Solution:
    def minimumLength(self, s: str) -> int:
        f = Counter(s)
        res = 0
        for c, cnt in f.items():
            if cnt <= 2:
                res+=cnt
            elif cnt%2==0:
                res+=2
            else:
                res+=1

        return res

        
