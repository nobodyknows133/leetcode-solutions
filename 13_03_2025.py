class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        def checkAllAreZero(nums):
            for x in nums:
                if x!=0:
                    return False
            return True


        if checkAllAreZero(nums):
            return 0

        l = 0
        r = len(queries)-1
        res = -1


        def checkWithDiffArr(nums, q, mid):
            diff = [0 for _ in range(len(nums))]
            for i in range(mid+1):
                s = q[i][0]
                e = q[i][1]
                x = q[i][2]
                diff[s]+=x
                if e+1<len(nums):
                    diff[e+1]-=x
            
            cumSum = 0
            for i in range(len(diff)):
                if i>0:
                    diff[i]+=diff[i-1]
            # print(diff)
            for i in range(len(diff)):
                if nums[i]-diff[i]>0:
                    return False
            return True 
                




        while l<=r:
            mid = l + (r-l)//2
            # print(l,r,mid,checkWithDiffArr(nums,queries,mid))
            if checkWithDiffArr(nums,queries,mid):
                res = mid + 1
                r = mid - 1
            else:
                l = mid + 1
        
        return res

        
