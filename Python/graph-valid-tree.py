# Time:  O(|V| + |E|)
# Space: O(|V|)

# BFS solution.
class Solution:
    # @param {integer} n
    # @param {integer[][]} edges
    # @return {boolean}
    def validTree(self, n, edges):
        if len(edges) != n - 1:
            return False
        elif n == 1:
            return True

        visited_from, neighbors = 0, 1
        nodes = {}  # A structure to track each node's [visited_from, neighbors]
        for i in xrange(n):
            nodes[i] = [-1, []]
        for edge in edges:
            nodes[edge[0]][neighbors].append(edge[1])
            nodes[edge[1]][neighbors].append(edge[0])

        # BFS to check whether the graph is valid tree.
        visited = {}
        q = collections.deque()
        q.append(edges[0][0])
        while q:
            i = q.popleft()
            visited[i] = True
            for n in nodes[i][neighbors]:
                if n != nodes[i][visited_from]:
                    if n in visited:
                        return False
                    else:
                        visited[n] = True
                        nodes[n][visited_from] = i
                        q.append(n)
        return True
