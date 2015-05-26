#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
	    int *mem=(int*)malloc(m*n*sizeof(int));
	    for(int i=0;i<n;i++){
	    	*(mem+i)=1;
	    }
	    for(int i=1;i<m;i++)
	    {
		    *(mem+i*n)=1;
		    for(int j=1;j<n;j++){
			    //mem[i][j]=m[i-1][j]+m[i][j-1];
			    *(mem+i*n+j)=*(mem+(i-1)*n+j)+*(mem+i*n+j-1);
		    
		    }
	    }
	    return *(mem+(m-1)*n+n-1);
    	    
    }
};
int main(){
	Solution *sol=new Solution;
	//sol->uniquePaths(2,2);
	cout<<sol->uniquePaths(3,3)<<endl;
}
