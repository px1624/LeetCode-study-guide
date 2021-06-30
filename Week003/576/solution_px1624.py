class Solution:
    def __init__(self):
        self.memo = {}
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        if (startRow, startColumn, maxMove) in self.memo:
            return self.memo[(startRow, startColumn, maxMove)]
        if startRow < 0 or startRow >= m or startColumn < 0 or startColumn >= n:
            return 1
        if maxMove <= 0:
            return 0
        num_path = 0
        num_path += self.findPaths(m, n, maxMove-1, startRow + 1, startColumn)
        num_path += self.findPaths(m, n, maxMove-1, startRow - 1, startColumn)
        num_path += self.findPaths(m, n, maxMove-1, startRow, startColumn - 1)
        num_path += self.findPaths(m, n, maxMove-1, startRow, startColumn + 1)
        self.memo[(startRow, startColumn, maxMove)] = num_path % (10**9 + 7)
        return num_path % (10**9 + 7)
