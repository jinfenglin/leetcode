#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int nrow,ncol;
		bool InsideBoundary(int i,int j){
			if(i<0 or i>nrow-1)
				return false;
			if(j<0 or j>ncol-1)
				return false;
			return true;
		}
		void DFS(vector<vector<char>>& board,int i,int j){
			if(board[i][j]=='O')
				board[i][j]='#';
			else
				return ;
			if(InsideBoundary(i+1,j))
				DFS(board,i+1,j);
			if(InsideBoundary(i-1,j))				
				DFS(board,i-1,j);
			if(InsideBoundary(i,j+1))
				DFS(board,i,j+1);
			if(InsideBoundary(i,j-1))
				DFS(board,i,j-1);
			
			
		}
		void solve(vector<vector<char>>& board){
			nrow=board.size();
			if(nrow==0)
				return;
			ncol=board[0].size();
			
			for(int i=0;i<nrow;i++){
				if(board[i][0]=='O')
					DFS(board,i,0);
				if(board[i][ncol-1]=='O')
					DFS(board,i,ncol-1);
			}
			for(int j=0;j<ncol;j++){
				if(board[0][j]=='O')
					DFS(board,0,j);
				if(board[nrow-1][j]=='O')
					DFS(board,nrow-1,j);
			}

			for(int i=0;i<nrow;i++)
				for(int j=0;j<ncol;j++){
					if(board[i][j]=='#')
						board[i][j]='O';
					else
						board[i][j]='X';
				}
		}
};
int main(){
	vector<char> vec1= {'O','O','O'};
	vector<char> vec2= {'O','O','O'};
	vector<char> vec3= {'O','O','O'};
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
