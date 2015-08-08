#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<set<char>> row_valid;
		vector<set<char>> list_valid;
		vector<set<char>> board_valid;

		void solveSudoku(vector<vector<char>>& board) {
			for(int i=0;i<9;i++){
				set<char> row={'1','2','3','4','5','6','7','8','9'};
				for(int j=0;j<9;j++){
					row.erase(board[i][j]);
				}
				row_valid.push_back(row);
			}
			for(int i=0;i<9;i++){
				set<char> list={'1','2','3','4','5','6','7','8','9'};
				for(int j=0;j<9;j++){
					list.erase(board[j][i]);
				}
				list_valid.push_back(list);
			}
			for(int i=0;i<9;i++){
				int row=i/3*3;
				int list=i%3*3;
				set<char> board_set={'1','2','3','4','5','6','7','8','9'};
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						board_set.erase(board[row+x][y+list]);
					}
				}
				board_valid.push_back(board_set);
			}
			solve(board,0,0);
		}
		bool solve(vector<vector<char>>& board,int i,int j){
			int next_i=i+j/8;
			int next_j=(j+1)%9;
			if(i==9)
				return true;

			if(board[i][j]!='.')
			{
				if(solve(board,next_i,next_j))
					return true;
			}else{
				for(int x=1;x<=9;x++){
					char num='0'+x;
					if(row_valid[i].count(num) and list_valid[j].count(num) and board_valid[(i/3)*3+j/3].count(num))
					{
						board[i][j]=num;//do recursive cal here 

						row_valid[i].erase(num);
						list_valid[j].erase(num);
						board_valid[(i/3)*3+j/3].erase(num);

						if(solve(board,next_i,next_j))
							return true;
						board[i][j]='.';
						row_valid[i].insert(num);
						list_valid[j].insert(num);
						board_valid[(i/3)*3+j/3].insert(num);
					}
				}

			}	
			return false;
		}
};

int main(){
	vector<char> v1={'5','3','.','.','7','.','.','.','.'};
	vector<char> v2={'6','.','.','1','9','5','.','.','.'};
	vector<char> v3={'.','9','8','.','.','.','.','6','.'};
	vector<char> v4={'8','.','.','.','6','.','.','.','3'};
	vector<char> v5={'4','.','.','8','.','3','.','.','1'};
	vector<char> v6={'7','.','.','.','2','.','.','.','6'};
	vector<char> v7={'.','6','.','.','.','.','2','8','.'};
	vector<char> v8={'.','.','.','4','1','9','.','.','5'};
	vector<char> v9={'.','.','.','.','8','.','.','7','.'};
	vector<vector<char>> board={v1,v2,v3,v4,v5,v6,v7,v8,v9};
	Solution *sol=new Solution;
	sol->solveSudoku(board);
	for(int a=0;a<9;a++)
	{
		for(int b=0;b<9;b++){
			cout<<board[a][b]<<" ";
		}
		cout<<endl;
	}
}
