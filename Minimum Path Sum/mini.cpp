#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void search(int **sum_map,vector<vector<int>>& grid,int m,int n){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(i==0 and j==0)
						continue;
					else if(i==0){
						sum_map[i][j]=sum_map[i][j-1]+grid[i][j];
					}else if(j==0){
						sum_map[i][j]=sum_map[i-1][j]+grid[i][j];
					}else{
						sum_map[i][j]=min(sum_map[i-1][j],sum_map[i][j-1])+grid[i][j];
					}
				}
			}
		}
		int minPathSum(vector<vector<int>>& grid) {
			int m=grid.size();
			if(m==0)
				return 0;
			int n=grid[0].size();
			int **sum_map=(int **)malloc(m*sizeof(int *));
			for(int i=0;i<m;i++){
				sum_map[i]=(int *)malloc(sizeof(int)*n);
			}
			sum_map[0][0]=grid[0][0];
			search(sum_map,grid,m,n);
			return sum_map[m-1][n-1];
		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> f1={1,2,3,4};
	vector<int> f2={5,6,7,8};
	vector<int> f3={9,10,11,12};
	vector<vector<int> > init={};
	cout<<sol->minPathSum(init)<<endl;
}
