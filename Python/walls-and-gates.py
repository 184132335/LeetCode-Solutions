# Time:  O(n^2)
# Space: O(n)

from collections import deque

class Solution(object):
    def wallsAndGates(self, a):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        for i in xrange(len(a)):
            for j in xrange(len(a[0])):
                if a[i][j] == 0:
                    q = deque([(i + 1, j, 1), (i - 1, j, 1), (i, j + 1, 1), (i, j - 1, 1)])
                    while q:
                        ii, jj, dist = q.popleft()
                        if ii < 0 or jj < 0 or ii >= len(a) or jj >= len(a[0]) or a[ii][jj] <= dist:
                            continue
                        a[ii][jj] = dist
                        q.append((ii + 1, jj, dist + 1))
                        q.append((ii - 1, jj, dist + 1))
                        q.append((ii, jj + 1, dist + 1))
                        q.append((ii, jj - 1, dist + 1))
