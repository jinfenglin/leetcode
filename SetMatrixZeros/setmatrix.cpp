#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void make_zero(int row,int col,vector<vector<int> > &matrix){
			int m=matrix.size();
			int n=matrix[0].size();
			for(int i=0;i<n;i++)
				if(matrix[row][i]!=0)
					matrix[row][i]=99999999;
			for(int i=0;i<m;i++){
				if(matrix[i][col]!=0)
					matrix[i][col]=99999999;
			}
		}
		void setZeroes(vector<vector<int>>& matrix) {
			int m=matrix.size();
			if(m==0)
				return;
			int n=matrix[0].size();
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					if(matrix[i][j]==0)
						make_zero(i,j,matrix);
				
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					if(matrix[i][j]==99999999)
						matrix[i][j]=0;
				
		}
};
int main(){
	Solution *sol= new Solution;
	vector<int > f1={1,2,3,4,5,0};
	vector<int > f2={1,1,0,1,1,0};
	vector<int > f3={1,1,1,1,1,1};
	vector<vector<int> > init={f1,f2,f3};
	sol->setZeroes(init);
	for(auto x: init){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
