#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > double_vec;

class Solution {
	public:
		vector<vector<int> > spiral(int x,int y,int n,int num,vector<vector<int> > matrix){
			if(n==0)
				return matrix;
			else if(n==1)
			{
				matrix[x][y]=num++;
				return matrix;
			}

		
			for(int i=0;i<n-1;i++)
				matrix[x][y+i]=num++;
			for(int i=0;i<n-1;i++)
				matrix[x+i][y+n-1]=num++;
			for(int i=0;i<n-1;i++)
				matrix[x+n-1][y+n-1-i]=num++;
			for(int i=0;i<n-1;i++)
				matrix[x+n-1-i][y]=num++;
			return spiral(x+1,y+1,n-2,num,matrix);
			//return matrix;
				
		}
		vector<vector<int> > generateMatrix(int n) {
			double_vec result;
			for(int i=0;i<n;i++){
				result.push_back(vector<int> (n,0));
			}
			result=spiral(0,0,n,1,result);
			return result;

		}
};
int main(){
	Solution *sol=new Solution;
	double_vec result=sol->generateMatrix(4);
	for(auto x:result){

		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

