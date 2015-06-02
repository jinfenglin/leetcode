#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int search_row(vector<vector<int> > matrix,int target){
			int start=0;
			int end=matrix.size()-1;
			
			while(start<=end){
				int mid=(start+end);
				if(matrix[mid][0]<=target and target<=matrix[mid][matrix[mid].size()-1])
					return mid;
				else if(matrix[mid][0]>target){
					end=mid-1;
				}else{
					start=mid+1;
				}
			}
			return -1;
			
		}
		int search_pos(vector<int> nums,int target){
			int start=0;
			int end=nums.size()-1;
			while(start<=end){
				int mid=(start+end)/2;
				if(nums[mid]==target)
					return mid;
				else if(nums[mid]>target)
					end=mid-1;
				else
					start=mid+1;
			}
			return -1;
		}
		bool searchMatrix(vector<vector<int> >& matrix, int target) {
			int row=search_row(matrix,target);
			if(row>=0){
				int col=search_pos(matrix[row],target);
				if(col>=0)
					return true;
				else
					return false;
			}
			else
				return false;
		}
};
int main(){
	vector<int> f1={1,3,5,7};
	vector<int> f2={10,11,16,20};
	vector<int> f3={23,30,34,50};
	vector<vector<int> > init={f1,f2,f3};
	Solution *sol=new Solution;
	cout<<sol->searchMatrix(init,3)<<endl;
}

