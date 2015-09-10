Contains Solutions for leetcode. All case tested and accepted except:
-Wordladder
-3Sum
-Insert Interval (TLE, it is O(n) algorithm but need to avoid merging for every interval)
-


SLOW:
-Combination Sum
-Binary Tree zigzag level order traverse( because I go through the deque for another time to generate the next layer which could be avoided)
-Palindrome partion(because keep copys of failed searching)

Not PASS:
-Word Break 2. Using DP+Backtracing, TLE for some reason
