#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void checkStatus(int i,int j,vector<vector<int>>& board){
			int x=board.size();
			int y=board[0].size();
			int count=0;
			for(int m=i-1;m<=i+1;m++)
				for(int n=j-1;n<=j+1;n++){
					if(m<x and m>=0 and n<y and n>=0 and !(m==i and n==j))
						count+= board[i][j]==1 or board[i][j]==-1;
				}
			if(board[i][j]==1){
				if(count<2)
					board[i][j]=-1;	
				else if(count>3)
					board[i][j]=-1;
			}else{
				if(count==3)
					board[i][j]=2;
			}
		}
		void gameOfLife(vector<vector<int>>& board) {
			int x,y;
			x=board.size();
			if(x>0)
				y=board[0].size();
			else
				return;

			for(int i=0;i<x;i++)
				for(int j=0;j<y;j++)
					checkStatus(i,j,board);
			for(int i=0;i<x;i++)
				for(int j=0;j<y;j++)
					if(board[i][j]>=1)
						board[i][j]=1;
					else
						board[i][j]=0;
		}
};
int main(){
}
