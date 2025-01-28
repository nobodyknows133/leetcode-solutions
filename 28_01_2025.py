class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        res = 0
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]

        def dfs(x,y):
            if grid[x][y]==0:
                return 0
            res = grid[x][y]
            grid[x][y]=0

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx>=0 and nx<len(grid) and ny>=0 and ny<len(grid[0]) and grid[nx][ny]>0:
                    res+=dfs(nx,ny)

            return res
        
        ans = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]>0:
                    ans = max(ans,dfs(i,j))
        

        return ans
                
        
