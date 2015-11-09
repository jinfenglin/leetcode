Contains Solutions for leetcode. All case tested and accepted except:
-Wordladder(need to build the graph first, simply bit flipping don't work)
-3Sum
-Insert Interval (TLE, it is O(n) algorithm but need to avoid merging for every interval)

Blur Logic:
SortList(have difficulties to deal with link relation between nodes, the solution is not elegant enough)
Buy and sell stock 4
Basic Cal(It is unbelievable that such a simple problem takes so much time)
Valid Number

SLOW:
-Combination Sum
-Binary Tree zigzag level order traverse( because I go through the deque for another time to generate the next layer which could be avoided)
-Palindrome partion(because keep copys of failed searching)
-Insertion sort, logic is a chaose, make 3 condition more clear.
-Populating Next Right Pointers in Each Node II(I used recursion)
-Word Search 2(Using trie tree, while should integrate the search process with this function)
-different ways to add parentheses
-merge k list(merge sort is faster)

Not PASS:
-Word Break 2. Using DP+Backtracing, TLE for some reason
