class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        t = [nums[i]-i for i in range(n)]
        res = 0
        m = defaultdict(int)
        for i in range(n):
            res+=m[t[i]]
            m[t[i]]+=1
    
        return (n*(n-1))//2 - res
        
