#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	    int m=obstacleGrid.size();
	    int n=obstacleGrid[0].size();
	    int *mem[m];
	    for(int i=0;i<m;i++){
		    mem[i]=(int *)malloc(n*sizeof(int));
		    memset(mem[i],0,sizeof(int)*n);
	    }
	   	    
	    mem[0][0]=1;
	    cout<<" initializing.."<<endl;
	    for(int i=0;i<m;i++)
	    {
		    for(int j=0;j<n;j++){
			    if(obstacleGrid[i][j]==1)
			    {
				    mem[i][j]=0;
				    continue;
			    }
			    if(i>0 and obstacleGrid[i-1][j]!=1)
				    mem[i][j]+=mem[i-1][j];
			    if(j>0 and obstacleGrid[i][j-1]!=1)
				    mem[i][j]+=mem[i][j-1]; 
			    //cout<<"i:"<<i<<" j:"<<j<<" num:"<<mem[i][j]<<endl;
		    }
	    }
	    return mem[m-1][n-1];
		        	    	    
        
    }
};
int main(){
	vector<int> f1={0,0,0};
	vector<int> f2={0,1,0};
	vector<int> f3={1};
	vector<vector<int > > init={f3};
	Solution *sol=new Solution;
	cout<<sol->uniquePathsWithObstacles(init)<<endl;
}
