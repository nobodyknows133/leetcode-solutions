class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        res = [x for x in nums]
        n = len(nums)
        for i in range(n):
            if i<n-1 and res[i]==res[i+1]:
                res[i]*=2
                res[i+1]=0


        sol = []
        for x in res:
            if x>0:
                sol.append(x)

        y=len(sol)
        while len(sol)!=n:
            sol.append(0)
        
        return sol


        
