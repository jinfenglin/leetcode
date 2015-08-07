#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool checkRow(int RowNum,char num,vector<vector<char>>& board){
			int count=0;
			for(int i=0;i<9;i++){
				if(board[RowNum][i]==num)
					count++;
			}
			if(count>1)
				return false;
			else
				return true;
		}
		bool checkList(int ListNum,char num,vector<vector<char>>& board){
			int count=0;
			for(int i=0;i<9;i++){
				if(board[i][ListNum]==num)
					count++;
			}
			if(count>1)
				return false;
			else
				return true;
	
		}
		bool checksquare(int x,int y,char num,vector<vector<char>>& board){
			int count=0;
			int start_x=x/3*3;
			int start_y=y/3*3;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(board[start_x+i][start_y+j]==num)
						count++;
				}
			}
			if(count>1)
				return false;
			else
				return true;			
		}
		bool isValidSudoku(vector<vector<char>>& board) {
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if(board[i][j]=='.')
						continue;
					bool c1,c2,c3;
					c1=checkRow(i,board[i][j],board);
					c2=checkList(j,board[i][j],board);
					c3=checksquare(i,j,board[i][j],board);
					if(!(c1 and c2 and c3))
						return false;
				}
			}
			return true;
		}
};

int main(){
	vector<char> v1={'5','3','.','7','.','.','.','.','.'};
	vector<char> v2={'6','.','.','1','9','5','.','.','.'};
	vector<char> v3={'.','9','8','.','.','.','.','6','.'};
	vector<char> v4={'8','.','.','.','6','.','.','.','3'};
	vector<char> v5={'1','.','.','.','.','.','.','.','.'};

	vector<char> v6={'.','.','.','.','.','.','.','.','.'};
	vector<char> v7={'.','.','.','.','.','.','.','.','.'};
	vector<char> v8={'.','.','.','.','.','.','.','.','.'};
	vector<char> v9={'.','.','.','.','.','.','.','.','.'};
	vector<vector<char>> board={v1,v2,v3,v4,v5,v6,v7,v8,v9};
	Solution *sol=new Solution;
	cout<<sol->isValidSudoku(board)<<endl;

}
