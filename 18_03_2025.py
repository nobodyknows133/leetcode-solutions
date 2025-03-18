class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        j = 0
        mask = 0
        res = 1
        while j<n and i<=j:
            while nums[j]&mask != 0:
                mask = mask ^ nums[i]
                i+=1
            res = max(res, j - i + 1)
            mask = mask | nums[j]
            j+=1
        
        return res

        
