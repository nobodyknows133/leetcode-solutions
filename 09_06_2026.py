class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        mx = -1
        mn = 1e9+5
        res = -1
        for x in nums:
            mx = max(mx,x)
            mn = min(mn,x)
            res = max(res,mx-mn)
        return res*k

        
