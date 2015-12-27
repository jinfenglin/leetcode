#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int height,width;
	bool DFS(vector<vector<char>>& board,int i,int j){
		if(i==0 or i==height-1 or j==0 or j==width-1){
			return true;
		}
		bool flag=false;
		char backup=board[i][j];
		board[i][j]='X';
		if(board[i-1][j]=='0')
			flag=flag||DFS(board,i-1,j);
		//cout<<flag;		
		if(board[i+1][j]=='0')
			flag=flag||DFS(board,i+1,j);
		//cout<<flag;
		if(board[i][j+1]=='0')
			flag=flag||DFS(board,i,j+1);
		//cout<<flag;
		if(board[i][j-1]=='0')
			flag=flag||DFS(board,i,j-1);
		//cout<<flag<<endl;
		if(flag){
			board[i][j]=backup;
		}
		return flag;
	}
	void solve(vector<vector<char>>& board) {
		height=board.size();
		width=0;
		if(height==0)
			return ;
		else
			width=board[0].size();

		//cout<<height<<" "<<width<<endl;
		for(int i=1;i<height-1;i++)
			for(int j=1;j<width-1;j++){
				DFS(board,i,j);
			}
		}
};
int main(){
	vector<char> vec1= {'0','0','0'};
	vector<char> vec2= {'0','x','0'};
	vector<char> vec3= {'0','0','0'};
	vector<vector<char>>test = {vec1,vec2,vec3};
	Solution *sol= new Solution;
	sol->solve(test);
	for(int i=0;i<test.size();i++){
		for(int j=0;j<test[0].size();j++){
			cout<<test[i][j]<<" ";
		}
		cout<<endl;
	}
}
