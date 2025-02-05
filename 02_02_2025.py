class Solution:
    def check(self, nums: List[int]) -> bool:
        s = sorted(nums)
        n = len(nums)
        if s==nums:
            return True
        f = False
        q = deque(nums)
        for i in range(n):
            x = q.popleft()
            q.append(x)

            if list(q)==s:
                f = True
                break
        
        return f



        return f
        
