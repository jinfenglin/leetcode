#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int x_len,y_len;
			x_len=matrix.size();
			if(x_len)
				y_len=matrix[0].size();
			else 
				return false;
			int y=y_len-1;
			for(int x=0;x<x_len;x++){				
				while(y>0 and target<matrix[x][y])
					y--;
				if(matrix[x][y]==target)
				{
					cout<<x<<" "<<y<<endl;
					cout<<matrix[x][y]<<endl;
					return true;
				}
			}
			return false;
		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> v1={1,1};
	vector<int> v2={2,5,8,12,19};
	vector<int> v3={3,6,9,16,22};
	vector<int> v4={10,13,14,17,24};
	vector<int> v5={18,21,23,26,30};
	vector<int> v6={19,22,24,27,31};

	vector<vector<int>> vec;
	vec.push_back(v1);
	//vec.push_back(v2);
	//vec.push_back(v3);
	//vec.push_back(v4);
	//vec.push_back(v5);
	//vec.push_back(v6);

	cout<<sol->searchMatrix(vec,0)<<endl;
}
