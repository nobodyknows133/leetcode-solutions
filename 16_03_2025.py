class Solution:
    
    def minCapability(self, nums: List[int], k: int) -> int:
        l = min(nums)
        r = max(nums)
        res = 10**10

        def isPoss(mid):
            a = []
            for i,x in enumerate(nums):
                if x<=mid:
                    a.append((i,x))
            cnt = 0
            i = 0
            n = len(a)
            while i<n:
                cnt+=1
                if i<n-1:
                    if a[i+1][0]==a[i][0]+1:
                        i=i+2
                    else:
                        i=i+1
                else:
                    i=i+1
            
            return cnt>=k

        while l<=r:
            mid = l + (r-l)//2
            if isPoss(mid):
                r = mid - 1
                res = min(mid, res)
            else:
                l = mid + 1

        return res
            
        

        
