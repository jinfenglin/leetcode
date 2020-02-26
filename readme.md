LeetCode 2020
===


<!--| ID|Time|Note|Optimal Solution|-->

1007 Minimum Domino Rotations For Equal Row  
___

时间: 25min  
错误内容：  
* Missed the case that column can have same numbers  
* Not optimal memory my solution have O(N) memory the optimal need O(1)  
最优解思路： 
可被替换的值必须来自A或者B. 遍历数组,如果每个位置上的数都等于A[0] (B[0]) 那么存在结果，
最小的替换数量根据A[0] (B[0])的存在数量而定.


843. Guess the Word
---
时间: ?
错误内容：
* 建立了一pairwise的table. 对于单次计算这样的table是不需要的
* 思路错了.不能用DFS的思路来解决它, 应该用binary search的方式来解因为这个search需要根据条件来不断缩小区间
* code 写的过于冗长. 最优解的代码非常的优雅, 主要是因为2点：
    * 用循环代替了递归
    * pythonic的写法 用slice的写法来代替了for 循环
    * 用lambda来代替的小型的函数