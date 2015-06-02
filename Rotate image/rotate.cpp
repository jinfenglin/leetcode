#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void rotate_layer(vector<vector<int>> &matrix,int x,int y,int length){		
		if(length<=1)
			return;
		for(int i=0;i<length-1;i++){
			int temp=matrix[x][y+i];
			matrix[x][y+i]=matrix[x+length-1-i][y];
			matrix[x+length-1-i][y]=matrix[x+length-1][y+length-1-i];
			matrix[x+length-1][y+length-1-i]=matrix[x+i][y+length-1];
			matrix[x+i][y+length-1]=temp;
		}
		rotate_layer(matrix,x+1,y+1,length-2);
	}
    void rotate(vector<vector<int>>& matrix) {
	    int n=matrix.size();
	    rotate_layer(matrix,0,0,n);
    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> f1={1,2,3,4};
	vector<int> f2={5,6,7,8};
	vector<int> f3={9,10,11,12};
	vector<int> f4={13,14,15,16};
	vector<vector<int> > init={};
	//vector<vector<int> > init={f1,f2,f3,f4};
	sol->rotate(init);

}
