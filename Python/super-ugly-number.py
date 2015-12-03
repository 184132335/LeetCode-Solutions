# Time:  O(n * k)
# Space: O(n + k)

# Write a program to find the nth super ugly number.
#
# Super ugly numbers are positive numbers whose all 
# prime factors are in the given prime list primes of size k.
# For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]
# is the sequence of the first 12 super ugly numbers given 
# primes = [2, 7, 13, 19] of size 4.
#
# Note:
# (1) 1 is a super ugly number for any given primes.
# (2) The given numbers in primes are in ascending order.
# (3) 0 < k <= 100, 0 < n <= 106, 0 < primes[i] < 1000.

# Hash solution. (932ms)
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        uglies, idx, ugly_by_prime, ugly_set = [0] * n, [0] * len(primes), [], set([1])
        uglies[0] = 1

        for k, p in enumerate(primes):
            heapq.heappush(ugly_by_prime, (p, k))
            ugly_set.add(p)

        for i in xrange(1, n):
            min_val, k = heapq.heappop(ugly_by_prime)
            uglies[i] = min_val
            while (primes[k] * uglies[idx[k]]) in ugly_set:
                idx[k] += 1
            heapq.heappush(ugly_by_prime, (primes[k] * uglies[idx[k]], k))
            ugly_set.add(primes[k] * uglies[idx[k]])

        return uglies[-1]


class Solution2(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        uglies, idx, ugly_by_prime = [1], [0] * len(primes), []
        for k, p in enumerate(primes):
            heapq.heappush(ugly_by_prime, (p, k))

        for i in xrange(1, n):
            min_val, k = ugly_by_prime[0]
            uglies += [min_val]

            while ugly_by_prime[0][0] == min_val:  # worst time: O(klogk)
                min_val, k = heapq.heappop(ugly_by_prime)
                idx[k] += 1
                heapq.heappush(ugly_by_prime, (primes[k] * uglies[idx[k]], k))

        return uglies[-1]
  
