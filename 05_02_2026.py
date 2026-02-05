class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*(len(nums))
        for i in range(n):
            if nums[i]>0:
                # move right
                res[i] = nums[(i+nums[i])%n]  
            elif nums[i]<0:
                res[i] = nums[(i-abs(nums[i])+n)%n]
            else:
                res[i] = nums[i]

        return res
        
