#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
	    if(m==1 or n==1)
		    return 1;
	    int part1=uniquePaths(m-1,n);
	    int part2=uniquePaths(m,n-1);
	    return part1+part2;
        
    }
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->uniquePaths(2,2)<<endl;
}
