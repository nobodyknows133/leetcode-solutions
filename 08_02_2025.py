from sortedcontainers import SortedSet
class NumberContainers:

    def __init__(self):
        self.nI = defaultdict(SortedSet)
        self.iN = {}
        

    def change(self, index: int, number: int) -> None:
        currNo = self.iN.get(index, None)
        if currNo:
            self.nI[currNo].remove(index)

        self.iN[index] = number
        self.nI[number].add(index)
        

    def find(self, number: int) -> int:
        if len(self.nI[number])>0:
            return self.nI[number][0]
        else:
            return -1

        


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
