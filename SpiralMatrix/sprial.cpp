#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > double_vec;
class Solution {
	public:
		vector<int> spiral(int x,int y,int x_length,int y_length,vector<vector<int>>& matrix){
			vector<int> result;
			if(x_length<=0 or y_length<=0)
				return result;
			else if(x_length==1){
				for(int i=0;i<=y_length-1;i++)
					result.push_back(matrix[x][y+i]);
				return result;

			}else if(y_length==1){
				for(int i=0;i<=x_length-1;i++)
					result.push_back(matrix[x+i][y]);
				return result;
			}

			for(int i=0;i<y_length-1;i++)
				result.push_back(matrix[x][y+i]);
			for(int i=0;i<x_length-1;i++)
				result.push_back(matrix[x+i][y+y_length-1]);
			for(int i=0;i<y_length-1;i++)
				result.push_back(matrix[x+x_length-1][y+y_length-1-i]);
			for(int i=0;i<x_length-1;i++)
				result.push_back(matrix[x+x_length-i-1][y]);
			vector<int> rest=spiral(x+1,y+1,x_length-2,y_length-2,matrix);
			result.insert(result.end(),rest.begin(),rest.end());
			return result;


		}
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			
			int m=matrix.size();
			if(m==0)
				return vector<int>();
			int n=matrix[0].size();
			return spiral(0,0,m,n,matrix);

		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> f1={1,2,3,10};
	vector<int> f2={4,5,6,11};
	vector<int> f3={7,8,9,12};
	vector<int> f4={13,14,15,16};

	//double_vec init={f1,f2,f3,f4};
	double_vec init;
	vector<int> result=sol->spiralOrder(init);
	for(int x:result){
		cout<<x<<" ";
	}

}
