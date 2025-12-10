class Solution:
    def countPermutations(self, c: List[int]) -> int:
        cnt = 0
        fl = False
        for i in range(1,len(c)):
            if c[i]<=c[0]:
                fl = True
                break
            else:
                # x>c[0]
                cnt+=1
        
        if fl:
            return 0
        # fact(cnt) ways of unlocking the other nums
        res = 1
        for i in range(1,cnt+1):
            res=(res*i)%(1e9+7)
        
        return int(res)
