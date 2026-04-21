class DSU:
    def __init__(self,n):
        self.par=[i for i in range(n)]
        self.sz = [1]*n

    def find(self,x):
        if self.par[x]!=x:
            self.par[x]=self.find(self.par[x])
        return self.par[x]
    
    def union(self,a,b):
        pa = self.find(a)
        pb = self.find(b)
        if self.sz[pa]<self.sz[pb]:
            self.par[pa]=pb
            self.sz[pb]+=self.sz[pa]
        else:
            self.par[pb]=pa
            self.sz[pa]+=self.sz[pb]

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        d = DSU(n)
        mp = defaultdict(lambda: defaultdict(int))
        for x,y in allowedSwaps:
            d.union(x,y)

        for i in range(n):
            mp[d.find(i)][source[i]]+=1

        res = 0
        for i in range(n):
            t = target[i]
            p = d.find(i)
            if mp[p][t]>0:
                mp[p][t]-=1
            else:
                res+=1

        return res

        
