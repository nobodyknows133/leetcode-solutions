class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        res = [0]*n
        l = 0
        for i in range(n):
            if nums[i]<pivot:
                res[l]=nums[i]
                l+=1
        for i in range(n):
            if nums[i]==pivot:
                res[l]=nums[i]
                l+=1
        for i in range(n):
            if nums[i]>pivot:
                res[l]=nums[i]
                l+=1
        
        return res


        
